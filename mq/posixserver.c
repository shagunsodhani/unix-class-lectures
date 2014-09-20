#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "common.h"

#define QUEUE_NAME  "/precise"

int main(int argc, char **argv)
{
    mqd_t mq;
    struct mq_attr attr;
    char buffer[MAX_SIZE + 1];
    int must_stop = 0;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 15;
    attr.mq_msgsize = 1;
    attr.mq_curmsgs = 0;

    /* create the message queue */
    mq = mq_open(QUEUE_NAME, O_CREAT  | O_RDONLY, 0644, &attr);
    CHECK((mqd_t)-1 != mq);
    mq_getattr(mq, &attr);
    printf("max #msgs = %ld, max #bytes/msg = %ld, "
           "#currently on queue = %ld\n",
           attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
    
    // mq_setattr()

    sleep(20);

    do {
        ssize_t bytes_read;

        /* receive the message */
        mq_getattr(mq, &attr);
        printf("max #msgs = %ld, max #bytes/msg = %ld, "
           "#currently on queue = %ld\n",
           attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
        bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        mq_getattr(mq, &attr);
    printf("max #msgs = %ld, max #bytes/msg = %ld, "
           "#currently on queue = %ld\n",
           attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
        CHECK(bytes_read >= 0);

        buffer[bytes_read] = '\0';
        if (! strncmp(buffer, MSG_STOP, strlen(MSG_STOP)))
        {
            must_stop = 1;
        }
        else
        {
            printf("Received: %s\n", buffer);
        }
    } while (!must_stop);

    /* cleanup */
    CHECK((mqd_t)-1 != mq_close(mq));
    CHECK((mqd_t)-1 != mq_unlink(QUEUE_NAME));

    return 0;
}