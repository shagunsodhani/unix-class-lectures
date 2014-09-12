/*
 * =====================================================================================
 *
 *       Filename:  uid.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 12 September 2014 01:47:20  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>

void display()
{
    printf("pid of the given process is : %d\n", getpid());
    printf("ppid of the given process is : %d\n", getppid());
    printf("real uid of the given process is : %d\n", getuid());
    printf("effective uid of the given process is : %d\n", geteuid());
    printf("real group id of the given process is : %d\n", getgid());
    printf("effective group id of the given process is : %d\n", getegid());
    return ;
}

int main()
{
    display();
    setuid(200);
    display();
    return 0;
}
