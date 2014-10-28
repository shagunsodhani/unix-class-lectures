/*
 * =====================================================================================
 *
 *       Filename:  unixbind.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 28 October 2014 02:03:12  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<sys/socket.h>
#include<strings.h>
#include<sys/un.h>
#include<errno.h>
#include<sys/signal.h>

#define SA  struct sockaddr

#define MAXLINE 512

void str_echo(int sockfd)
{
    ssize_t n;
    char buf[MAXLINE];
    while(1)
    {
        n = read(sockfd, buf, MAXLINE);
        if(n>0)
            write(sockfd, buf, n);
        else
        {
            if(errno == EINTR)
                continue;
            else
                printf("Read Error in str_echo");
        }
    }
}

int main(int argc, char **argv)
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_un servaddr, cliaddr;

    //void sigchld(int);

    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(argv[1]);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, argv[1]);

    bind(listenfd, (SA *) &servaddr, SUN_LEN(&servaddr));
    
    listen(listenfd, 10);
    
   // signal(SIGCHLD, sigchld);

    while(1)
    {
        clilen = sizeof(cliaddr);
        if( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen) < 0) )
        {
            if(errno == EINTR)
                continue;
            else
                printf("Accept Error\n");
        }
        if( (childpid = fork()) == 0)
        {
            //Child Process
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}
