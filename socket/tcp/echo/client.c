#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv[]){
    int connfd;
    int n, m;
    struct sockaddr_in servaddr;
    char ch[1024];
    connfd=socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1"); /* Check for server on loopback */
    servaddr.sin_port=htons(29008);
    if(connect(connfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("connect error");
        return -1;
    }
    // n=read(stdin, ch, 1024);
    while( fgets(ch, 1024, stdin) != NULL )
    {
        n = strlen(ch);
        // printf("n = %d\n", n);
        write(connfd, ch, n);
        if(read(connfd, ch, 1024) <0 )
            printf("Read error\n");
        fputs(ch, stdout);
    }
    close(connfd);
    return 0;
}
/*
connect()
    connect() system call to connect the socket referred to by sockfd to the address specified by addr.
    The returned descriptor will be used to communicate to the specified address.
*/