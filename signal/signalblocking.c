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

void catcher(int sig)
{
    printf("SIGINT caught!\n");
}

int main()
{
    sigset_t sigset;
    sigprocmask(0, NULL, &sigset);
    sigfillset(&sigset);
    sigdelset(&sigset, SIGINT);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT is included\n");
    else
        printf("SIGINT is not included\n");
    signal(SIGINT, catcher);
    //signal(SIGCONT, catcher);
    //kill(0, SIGINT);
    //kill(0, SIGCONT);
    printf("SIGINT shld be caught after this.\n");
    sleep(10);
    sigdelset(&sigset, SIGINT);
    printf("SIGINT shld have been caught before this.\n");
}
