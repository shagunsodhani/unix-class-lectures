/*
 * =====================================================================================
 *
 *       Filename:  sigprocmask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 09:21:51  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<signal.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    sigset_t sigset;
    sigprocmask(0, NULL, &sigset);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
    sigemptyset(&sigset);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
    sigfillset(&sigset);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
    sigdelset(&sigset, SIGINT);
    if(sigismember(&sigset, SIGINT))
         printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
    sigaddset(&sigset, SIGINT);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
}
