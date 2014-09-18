/*

 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 August 2014 03:12:18  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	pid_t childpid;
	char buffer[80];
	char message[] = "Hello, World!\n";
	pipe(fd);

	//fcntl(fd, F_SETFD, FD_CLOEXEC);
	
    if( ( childpid=fork() ) == -1)
		printf("Error in fork\n");
	else if(childpid==0)
	{
        sleep(2);
		//child process
		close(fd[0]);
		write(fd[1], message, (strlen(message) + 1));
		printf("buffering");
        
        /*  
        childpid = fork();
        if(childpid==0)
        {
            printf("Inside child");
            fflush(stdout);
            _exit(0);
        }
        */
        //fflush(stdout);
        exit(0);

	}
	else
	{
		// wait(childpid);
		//sleep(3);
		printf("sleepover");
		//parent process
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
        printf("Recieved string is : %s", buffer);   
		exit(0);
	}
	return(0);
}
