// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef MUDUO_NET_EVENTLOOPTHREAD_H
#define MUDUO_NET_EVENTLOOPTHREAD_H

#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>
#include <muduo/base/Thread.h>

#include <boost/noncopyable.hpp>

namespace muduo
{
namespace net
{

class EventLoop;

class EventLoopThread : boost::noncopyable//如果按照面向对象的编程思想，他应该继承自一个thread类
										  //这里是基于对象的编程思想，包含一个thread_对象
{
 public:
  typedef boost::function<void(EventLoop*)> ThreadInitCallback;

  EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback());//默认是空的回调函数，可以传递一个回调函数进来
  ~EventLoopThread();
  EventLoop* startLoop();	// 启动线程，调用Thread的start函数,该线程就成为了IO线程（线程函数就运行起来了）

 private:
  void threadFunc();		// 线程函数,函数里创建eventloop对象，下面的loop_指向这个对象

  EventLoop* loop_;			// loop_指针指向一个EventLoop对象(一个线程只有一个eventloop对象)
  bool exiting_;  //是否退出
  Thread thread_;//基于对象的编程思想，如果是面向对象则用继承
  MutexLock mutex_;
  Condition cond_;
  ThreadInitCallback callback_;		// 回调函数（若不为空）在EventLoop::loop事件循环之前被调用（相当于初始化后再调用事件循环loop()）
};

}
}

#endif  // MUDUO_NET_EVENTLOOPTHREAD_H

