/*
 * =====================================================================================
 *
 *       Filename:  basic.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 04:42:49  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fifo1, fifo2;
    fifo1 = open("/tmp/fifo1", O_RDONLY);
    char *buffer;
    int n = read(fifo1, buffer, 1024);
    int i;
    printf("Buffer Contained %d characters \n",n);
    printf("Buffer Contained %x characters \n",&n);
    for(i=0;i<n;++i)
        printf("%c",buffer[i]);
    printf("\n");
    pause();
    close(fifo1);
    unlink("/tmp/fifo1");
}



