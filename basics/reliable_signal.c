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

void catcher(int signo)
{
    printf("signal : %d\n", signo);
    sleep(10);
}

int main()
{
    printf("%d", getpid());
    signal(SIGINT, catcher);
    signal(SIGHUP, catcher);
    while(1)
    {
        ;
    }
    return 0;
}
