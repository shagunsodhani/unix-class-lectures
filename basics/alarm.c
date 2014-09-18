/*
 * =====================================================================================
 *
 *       Filename:  alarm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 08:35:26  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<signal.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    printf("Bomb planted at site A!\n");
    alarm(5);
    printf("There goes the bomb...!\n");
    sleep(1);
    sleep(2);
    signal(SIGALRM, SIG_IGN);
    sleep(5);
    printf("The bomb diffuesd\n");
}
