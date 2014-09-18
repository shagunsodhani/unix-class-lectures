/*
 * =====================================================================================
 *
 *       Filename:  processgroup.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 06:19:20  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("process id is %d\n", getpid());
    printf("process group id is %d\n", getpgrp());
    printf("process session id is %d\n", getsid(0));
    if(fork() == 0)
    {
        /* child process */
        printf("process id of child is %d\n", getpid());
        printf("process group id of child is %d\n", getpgrp());
        printf("process session id of child is %d\n", getsid(0));
        printf("changing the group id. Status = %d\n", setpgid(0, getpid()) );
        printf("New session id = %d\n", setsid() );
        printf("New process id of child is %d\n", getpid());
        printf("New process group id of child is %d\n", getpgrp());
        printf("process session id of child is %d\n", getsid(0));
    }
    else
    {
        /* Parent Process */
        printf("process id of parent is %d\n", getpid());
        printf("process group id of parent is %d\n", getpgrp());

    }
}
