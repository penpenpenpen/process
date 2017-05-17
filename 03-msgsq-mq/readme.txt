创建消息队列
	msgcreate <pathname>
删除消息队列
	msgrm <pathname>
发送消息
	msgsend [-n] <pathname> <message> <type>
接受消息
	msgrecv [-n] <pathname> <type>


type
msgsend /tmp/123abc msg1 3
msgsend /tmp/123abc msg2 4
msgsend /tmp/123abc msg3 2
msgrecv /tmp/123abc 0
msgrecv /tmp/123abc 0
msgrecv /tmp/123abc 0


msgsend /tmp/123abc msg1 3
msgsend /tmp/123abc msg2 4
msgsend /tmp/123abc msg3 2

msgrecv /tmp/123abc 2 2 
msgrecv /tmp/123abc 2 2 


msgsend /tmp/123abc msg1 3
msgsend /tmp/123abc msg2 4
msgsend /tmp/123abc msg3 2
msgrecv /tmp/123abc 2 -3 
msgrecv /tmp/123abc 2 -3 
msgrecv /tmp/123abc 2 -3 
