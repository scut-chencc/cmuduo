set(net_SRCS
  Acceptor.cc
  Buffer.cc
  Channel.cc
  Connector.cc
  EventLoop.cc
  EventLoopThread.cc
  EventLoopThreadPool.cc
  InetAddress.cc
  Poller.cc
  poller/DefaultPoller.cc
  poller/EPollPoller.cc
  poller/PollPoller.cc
  Socket.cc
  SocketsOps.cc
  TcpClient.cc
  TcpConnection.cc
  TcpServer.cc
  Timer.cc
  TimerQueue.cc
  )

add_library(muduo_net ${net_SRCS})#上面那么多文件编译生成一个库muduo_net
target_link_libraries(muduo_net muduo_base)#依赖于muduo基础库

install(TARGETS muduo_net DESTINATION lib)#安装的话把一些头文件安装过去，把头文件安装到相应目录
set(HEADERS
  Acceptor.h
  Buffer.h
  Channel.h#为了方便回调（外部使用），设置为外部类
  Endian.h
  EventLoop.h
  EventLoopThread.h
  EventLoopThreadPool.h
  Endian.h
  InetAddress.h
  TcpConnection.h
  TcpServer.h
  TimerId.h
  )
install(FILES ${HEADERS} DESTINATION include/muduo/net)

add_subdirectory(http)#添加子目录
add_subdirectory(inspect)
#
if(NOT CMAKE_BUILD_NO_EXAMPLES)
  add_subdirectory(tests)
endif()
#
#if(PROTOBUF_FOUND)
#  add_subdirectory(protorpc)
#else()
#  add_subdirectory(protorpc EXCLUDE_FROM_ALL)
#endif()
