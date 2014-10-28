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

void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];
    while(fgets(sendline, MAXLINE, fp)!=NULL)
    {
        write(sockfd, sendline, strlen(sendline));
        /*  if(readline(sockfd, recvline, MAXLINE) == 0 )
        {
            printf("str_cli : Server terminated prematurely");
            break;
        }*/
       fputs(recvline, stdout);
    }
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_un servaddr;

    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(argv[1]);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, argv[1]);

    connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
    str_cli(stdin, sockfd);
    return 0;
}
