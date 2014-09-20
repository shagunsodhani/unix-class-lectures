#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>

#include "common.h"

#define QUEUE_NAME  "/test1q2"

int main(int argc, char **argv)
{
    mq_unlink(QUEUE_NAME);
    mqd_t mq;
    char buffer[MAX_SIZE];

    struct mq_attr attr;
    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 15;
    attr.mq_msgsize = 1;
    attr.mq_curmsgs = 0;

    /* open the mail queue */
    mq = mq_open(QUEUE_NAME, O_RDWR | O_CREAT, 0666, attr);

    CHECK((mqd_t)-1 != mq);

    memset(buffer, 0, MAX_SIZE);
    fgets(buffer, MAX_SIZE, stdin);

    CHECK(0 <= mq_send(mq, buffer, MAX_SIZE, 0));

    fgets(buffer, MAX_SIZE, stdin);

    CHECK(0 <= mq_send(mq, buffer, MAX_SIZE, 0));

    fgets(buffer, MAX_SIZE, stdin);

    CHECK(0 <= mq_send(mq, buffer, MAX_SIZE, 0));
    
    mq_getattr(mq, &attr);
    printf("max #msgs = %ld, max #bytes/msg = %ld, "
           "#currently on queue = %ld\n",
           attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

    printf("Sending...\n");


    ssize_t bytes_read;

    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    /* receive the message */
    
    // CHECK(bytes_read >= 0);

    printf("Received: %s\n", buffer);

    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    /* receive the message */
    
    // CHECK(bytes_read >= 0);

    printf("Received: %s\n", buffer);

    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    /* receive the message */
    
    // CHECK(bytes_read >= 0);

    printf("Received: %s\n", buffer);

    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    /* receive the message */
    
    // CHECK(bytes_read >= 0);

    printf("Received: %s\n", buffer);    
    mq_getattr(mq, &attr);
    printf("max #msgs = %ld, max #bytes/msg = %ld, "
           "#currently on queue = %ld\n",
           attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

    /* cleanup */
    CHECK((mqd_t)-1 != mq_close(mq));
    CHECK((mqd_t)-1 != mq_unlink(QUEUE_NAME));

    return 0;
}
