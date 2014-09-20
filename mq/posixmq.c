#include <fcntl.h> /* Defines O_* constants */
#include <sys/stat.h> /* Defines mode constants */
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *qname = "/temp/q1";

	int flags = O_RDWR|O_CREAT;

	// struct mq_attr
	// {
	// 	long mq_flags;
	// 	long mq_maxmsg; 
	// 	long mq_msgsize; 
	// 	long mq_curmsgs; 
	// };
	//`struct mq_attr attr1;
	//  // = new (struct mq_attr);
	
    //attr1.mq_maxmsg = 10;
	//attr1.mq_msgsize = 100;
    //	mqd_t queue1 = mq_open(qname, flags, 0666, &attr1);
    //
	mqd_t queue1 = mq_open(qname, flags, 0666);
    printf("%d", queue1);
	
	char *message = "Hello World";
	char *message2 = "Welcome onboard";
	mq_send(queue1, message, sizeof(message), 1);
	mq_send(queue1, message2, sizeof(message2), 2);
	int *priority1, *priority2;
	char *rmessage;
	char *rmessage2;
	mq_receive(queue1, rmessage2, 100, priority1);
	printf("%s",rmessage2);
	mq_unlink(qname);

	// printf("MQ_OPEN_MAX = %ld\nMQ_PRIO_MAX = %ld\n",sysconf(_SC_MQ_OPEN_MAX), sysconf(_SC_MQ_PRIO_MAX ) );
}
