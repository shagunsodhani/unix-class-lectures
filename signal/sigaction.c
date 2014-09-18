/*
 * =====================================================================================
 *
 *       Filename:  sigaction.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 11:44:23  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<signal.h>

void catcher(int signo)
{
    printf("SIGINT caught!\n");
   // printf("signal caught was %d\n",info->si_code);
}

int main()
{
    struct sigaction sig, osig;
    sig.sa_handler = catcher;
    sigaction(SIGINT, &sig, &osig);
    printf("Ready to send SIGINT\n");
    sleep(5);
///    printf("Address of old = %d\n",osig.sa_handler);
    //printf("Address of new = %d\n",sig.sa_handler);
}
