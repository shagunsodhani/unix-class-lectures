#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t childpid;

    if( ( childpid=fork() ) == -1)
        printf("Error in fork\n");
    
    else if(childpid==0)
    {
        //child process
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls", "ls", NULL);
    }
    else
    {
        //parent process
        close(fd[1]);
        dup2(fd[0],0);
        // execve("ls");
        execlp("more", "more", NULL);
        //execve("more", "more", NULL);

    }
    return(0);
}
