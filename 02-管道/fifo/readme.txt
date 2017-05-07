1.创建命名管道 fifocreate.c
2.读写管道数据
  写入命名管道 fifowrite.c
  读取命名管道 fiforead.c
  注意：fifowrite与fiforead要同时执行，才会数据传递。否则会阻塞。
  不恰当的非阻塞方式
    写入命名管道 fifowrite01.c
    读取命名管道 fiforead01.c
  正确的非阻塞方式
    写入命名管道 fifowrite02.c
    读取命名管道 fiforead02.c
  注意：fcntl(fd,F_SETFL,O_NONBLOCK)不能控制命名管道读写阻塞问题。必须在open命名管道时，指定非阻塞打开。
3.删除命名管道 fiform.c