/*
 * =====================================================================================
 *
 *       Filename:  signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 12 September 2014 02:21:59  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <signal.h>
#include <stdio.h>

voi catcher(int signo)
{
    printf("signal : %d\n", &signo);
}

void sig_usr(int signo)
/* argument is signal number */
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        printf("received signal %d\n", signo);
}

int main()
{

    while(1)
    {
        signal(SIGABRT, SIG_IGN);
        signal(SIGUSR1, sig_usr);
    }
    return 0;
}
