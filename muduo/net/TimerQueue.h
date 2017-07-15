﻿// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is an internal header file, you should not include this.

#ifndef MUDUO_NET_TIMERQUEUE_H
#define MUDUO_NET_TIMERQUEUE_H

#include <set>
#include <vector>

#include <boost/noncopyable.hpp>

#include <muduo/base/Mutex.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/Channel.h>

namespace muduo
{
namespace net
{

class EventLoop;
class Timer;
class TimerId;

///
/// A best efforts timer queue.
/// No guarantee that the callback will be on time.
///
class TimerQueue : boost::noncopyable
{
 public:
  TimerQueue(EventLoop* loop);//属于一个eventloop，
  ~TimerQueue();

  ///
  /// Schedules the callback to be run at given time,
  /// repeats if @c interval > 0.0.
  ///
  /// Must be thread safe. Usually be called from other threads.
  // 一定是线程安全的，可以跨线程调用（可不在所属eventloop对象的线程当中）。通常情况下被其它线程调用。
  TimerId addTimer(const TimerCallback& cb,
                   Timestamp when,
                   double interval);

  void cancel(TimerId timerId);//也可以跨线程

 private:

  // FIXME: use unique_ptr<Timer> instead of raw pointers.
  // unique_ptr是C++ 11标准的一个独享所有权的智能指针（现在编译器还不能支持c++标准），用这个不用手动调用delete
  // 无法得到指向同一对象的两个unique_ptr指针
  // 但可以进行移动构造与移动赋值操作，即所有权可以移动到另一个对象（而非拷贝构造），涉及右值引用问题
  // 如果用共享智能指针share_ptr有点大题小做，效率低点
  typedef std::pair<Timestamp, Timer*> Entry;
  typedef std::set<Entry> TimerList;//按照时间戳排序
  typedef std::pair<Timer*, int64_t> ActiveTimer;//定时器地址、序号
  typedef std::set<ActiveTimer> ActiveTimerSet;//两个集合set保存相同的东西，一个按时间戳排序，一个按地址排序；

  // 以下成员函数只能在其所属的I/O线程中调用，因而不必加锁。
  // 服务器性能杀手之一是锁竞争，所以要尽可能少用锁
  void addTimerInLoop(Timer* timer);
  void cancelInLoop(TimerId timerId);
  // called when timerfd alarms
  void handleRead();
  // move out all expired timers
  // 返回超时的定时器列表
  std::vector<Entry> getExpired(Timestamp now);
  void reset(const std::vector<Entry>& expired, Timestamp now);//超时的可能是重复定时器，所以重置

  bool insert(Timer* timer);

  EventLoop* loop_;		// 所属EventLoop
  const int timerfd_;	//timerfd_create()产生的
  Channel timerfdChannel_;//可读事件到来时，回调handleRead();
  // Timer list sorted by expiration
  TimerList timers_;	// timers_是按到期时间排序

  // for cancel()
  // timers_与activeTimers_保存的是相同的数据
  // timers_是按到期时间排序，activeTimers_是按对象地址排序
  ActiveTimerSet activeTimers_;
  bool callingExpiredTimers_; /* atomic *///是否处于调用处理那些超时的定时器当中
  ActiveTimerSet cancelingTimers_;	// 保存的是被取消的定时器
};

}
}
#endif  // MUDUO_NET_TIMERQUEUE_H
