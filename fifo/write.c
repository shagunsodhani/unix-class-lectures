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
    mkfifo("/tmp/fifo1", 0666);
    fifo1 = open("/tmp/fifo1", O_WRONLY);
    char *buffer = "TEST";
    write(fifo1, buffer, sizeof(buffer));
    close(fifo1);
    unlink("/tmp/fifo1");
}



