/*
 * =====================================================================================
 *
 *       Filename:  basicsysV.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 09:46:22  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

typedef struct msgbuf
{
    int mtype;
    char* mtext;
} msg;

int main()
{
    key_t key = ftok("/tmpV2", 0);
    int flags = O_RDWR | IPC_CREAT;
    int msqid = msgget(IPC_PRIVATE,flags);
    printf("%d\n",msqid);

    // pid_t childpid = fork();
    // if(childpid == 0)
    // {
    //     //child
    //     msg* ptr;
    //     printf("pid of child is %d\n",getpid());
    //     int len = 6;
    //     ptr = (msg*)calloc(sizeof(int) + len, sizeof(char));
    //     ptr->mtype = 3;
    //     ptr->mtext = "shagn3";
    //     msgsnd(msqid, ptr, len, 0);

    //     ptr->mtype = 2;
    //     ptr->mtext = "shagn2";
    //     msgsnd(msqid, ptr, len, 0);

    //     ptr->mtype = 4;
    //     ptr->mtext = "shagn4";
    //     msgsnd(msqid, ptr, len, 0);

    //     ptr->mtype = 1;
    //     ptr->mtext = "shagn1";
    //     msgsnd(msqid, ptr, len, 0);

    //     msgctl(msqid, IPC_STAT, &ptr);
    //     printf("read-write: %03o, cbytes = %d, qnum = %d, qbytes = %d\n",
    //        ptr->msg_perm.mode & 0777, ptr->msg_cbytes,
    //        ptr->msg_qnum, ptr->msg_qbytes);
    //     // printf("message sent from child\n");
    //     // msgrcv(msqid, &ptr, 10, 3, 0);
    //     // printf("In parent, message = %s", ptr->mtext);
    //     exit(0);
    // }
    // else
    // {
        
    //     // wait(NULL);
    //     // sleep(3);
    //     // printf("pid of parent is %d\n",getpid());
    //     // msg* ptr1;
    //     // msgrcv(msqid, &ptr1, 10, 0, 0);
    //     // printf("In parent, message = %s", ptr1->mtext);

    // }
    sleep(20);
    msgctl(msqid, IPC_RMID, NULL);
    printf("sleep over :)\n");
}   
