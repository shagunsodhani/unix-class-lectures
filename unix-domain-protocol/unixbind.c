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

#define SA  struct sockaddr

//#define SUN_LEN(su) (sizeof(*(su)) - sizeof( (su)->sun_path ) + strlen((su)-sun_path))

int main(int argc, char **argv)
{
    int sockfd;
    socklen_t len;
    struct sockaddr_un servaddr, cliaddr;
    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(argv[1]);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, argv[1]);
    bind(sockfd, (SA *) &servaddr, SUN_LEN(&servaddr));
    len = sizeof(cliaddr);
    getsockname(sockfd, (SA*) &cliaddr, &len);
    printf("bound name = %s, returned len = %d\n", cliaddr.sun_path, len);
    return 0;
}
