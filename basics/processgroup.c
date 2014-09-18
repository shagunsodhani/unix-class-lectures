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
    printf("process group id is %d\n", getpgid(0));
    if(fork() == 0)
    {
        /* child process */
        printf("process id of child is %d\n", getpid());
        printf("process group id of child is %d\n", getpgrp());
        printf("status = %d\n", setpgid(0, getpid()) );
        printf("New process id of child is %d\n", getpid());
        printf("New process group id of child is %d\n", getpgrp());

    }
    else
    {
        /* Parent Process */
        printf("process id of parent is %d\n", getpid());
        printf("process group id of parent is %d\n", getpgrp());

    }
}
