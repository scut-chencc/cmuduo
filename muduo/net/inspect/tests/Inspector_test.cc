#include <muduo/net/inspect/Inspector.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/EventLoopThread.h>

using namespace muduo;
using namespace muduo::net;

int main()
{
  EventLoop loop;
  EventLoopThread t;	// 监控线程(在原有基础额外开的）
  Inspector ins(t.startLoop(), InetAddress(12345), "test");//这个对象在主线程中构造
  //t.startLoop()返回eventloop对象传递给inspector,inspector所属的io线程是t.startLoop(),而不是主线程（？）;
  //这个对象本身是主线程创建的，但是这个对象的server_所属的eventloop是inspector对象里的loop
  loop.loop();
}

