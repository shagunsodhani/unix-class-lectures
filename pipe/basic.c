/*
 * =====================================================================================
 *
 *       Filename:  pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 August 2014 02:56:17  IST
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
#include<sys/types.h>
int main()
{
    int fd[2];
    char string[] = "TEST";
    char buffer[80];

    pipe(fd);
    write(fd[1], string, (strlen(string)+1) );
    int n = read(fd[0], buffer, sizeof(buffer));
    printf("%d\n", n);
    printf("Received string is : \n");
    int i= 0;
    for(; i<n; ++i)
        printf("%c",buffer[i]);
    printf("\n");

}
