// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)

#include <muduo/net/EventLoopThread.h>

#include <muduo/net/EventLoop.h>

#include <boost/bind.hpp>

using namespace muduo;
using namespace muduo::net;


EventLoopThread::EventLoopThread(const ThreadInitCallback& cb)
  : loop_(NULL),
    exiting_(false),
    thread_(boost::bind(&EventLoopThread::threadFunc, this)),//指定的回调函数threadFunc，并且把自身对象EventLoopThread传递到threadFunc当中
    mutex_(),
    cond_(mutex_),
    callback_(cb)
{
}

EventLoopThread::~EventLoopThread()
{
  exiting_ = true;
  loop_->quit();		// 退出IO线程，让IO线程的loop循环退出，从而退出了IO线程
  thread_.join();
}

EventLoop* EventLoopThread::startLoop()//启动之后就为IO线程
{
  assert(!thread_.started());//假设线程还没有启动
  thread_.start();//启动线程，启动后线程函数就运行起来了(调用了绑定的回调函数，即threadFunc回调函数）,
					//这里就有两个线程，然后startLoop()接下去的部分和threadFunc()的执行顺序是不确定的，所以这里用了个条件变量在等待

  {
    MutexLockGuard lock(mutex_);
    while (loop_ == NULL)
    {
      cond_.wait();
    }
  }

  return loop_;
}

void EventLoopThread::threadFunc()
{
  EventLoop loop;

  if (callback_)
  {
    callback_(&loop);//调用回调函数，初始化
  }

  {
    MutexLockGuard lock(mutex_);
    // loop_指针指向了一个栈上的对象，threadFunc函数退出之后，这个指针就失效了
    // threadFunc函数退出，就意味着线程退出了，（线程对象）EventLoopThread对象也就没有存在的价值了。
    // 因而不会有什么大的问题
    loop_ = &loop;
    cond_.notify();
  }

  loop.loop();
  //assert(exiting_);
}

