/*
 * =====================================================================================
 *
 *       Filename:  reentrant.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  Friday 12 September 2014 02:51:29  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <signal.h>
#include <pwd.h>
#include <stdio.h>

void my_alarm(int signo)
{
    struct passwd *rootptr;
    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
        printf("getpwnam(root) error\n");
    alarm(1);
}

int main(void)
{
    struct passwd *ptr;
    signal(SIGALRM, my_alarm);
    //alarm(1);
    while(1)
    {
        if ((ptr = getpwnam("shagun")) == NULL)
            printf("getpwnam error\n");
        if (strcmp(ptr->pw_name, "shagun") != 0)
            printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
    }
}
