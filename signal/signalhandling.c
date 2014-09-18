/*
 * =====================================================================================
 *
 *       Filename:  signalhandling.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 12 September 2014 03:50:03  IST
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

static void sig_quit(int);

int main(void)
{
    printf("%d\n", getpid());
    sigset_t newmask, oldmask, pendmask;
    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
    printf("can't catch SIGQUIT\n");
    /*
    * Block SIGQUIT and save current signal mask.
    */
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("SIG_BLOCK error\n");
    sleep(30);
    /* SIGQUIT here will remain pending */
    if (sigpending(&pendmask) < 0)
        printf("sigpending error\n");
    if (sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");
    /*
    * Reset signal mask which unblocks SIGQUIT.
    */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf("SIG_SETMASK error\n");
    printf("SIGQUIT unblocked\n");
    sleep(15);
    exit(0);
    /* SIGQUIT here will terminate with core file */
}

static void sig_quit(int signo) 
{
    printf("caught SIGQUIT\n");
    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
        printf("can't reset SIGQUIT\n");
}
