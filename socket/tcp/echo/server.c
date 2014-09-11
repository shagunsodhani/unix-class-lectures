#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int listenfd, connfd;
    socklen_t len;
    pid_t pid;
    struct sockaddr_in servaddr, cliaddr;
    time_t ticks;
    char buff[2048];

    listenfd=socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET; /* Set Address Family to Internet */
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY); /* Any Internet address */
    servaddr.sin_port=htons(29008); /* Set server port to 29009 */
                        /* select any arbitrary Port > 1024 */
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 1);

    int n, m;

    while(1)
    {
        
        connfd=accept(listenfd, (struct sockaddr *)&cliaddr, &len);

        if ( (pid = fork()) == 0)
        {
            close(listenfd);
            printf("Server is waiting\n");
            while(n = read(connfd, buff, 1024) > 0)
            {
                printf("%s", buff);
                write(connfd, buff, n);
                write(stdout, buff, n);
            }
            if(n<0)
                printf("Read Error");    
            close(connfd);
            exit(0);
        }
        
        close(connfd);
    }
}
/*
struct sockaddr_in
    Used to hold an Internet(IP) address in the sin_addr
    which is of the type struct in_addr and hols a 32-bit unsigned integer.
    The port number is held in the sin_port, an unsigned 16-bit integer (so port numbers must be less than 65536)

socket()
    A successful call to socket() returns a descriptor that will be used for end-point communication
    int socket(int domain, int type, int protocol);
        domain: specifies a communication domain - the protocol family to be used for communication
            AF_UNIX, AF_LOCAL   Local communication
            AF_INET             IPv4 Internet protocols
            AF_INET6            IPv6 Internet protocols
            AF_IPX              IPX — Novell protocols
            AF_NETLINK          Kernel user interface device
            AF_X25              ITU-T X.25 / ISO-8208 protocol
            AF_AX25             Amateur radio AX.25 protocol
            AF_ATMPVC           Access to raw ATM PVCs
            AF_APPLETALK        AppleTalk
            AF_PACKET           Low-level packet interface  
            *AF stands for Address Family
        type: specifies the type of communication
            SOCK_STREAM     Sequenced, reliable, two-way, connection-based byte stream (TCP,SCTP, etc)
            SOCK_DGRAM      Datagrams — connectionless, unreliable (UDP)
            SOCK_SEQPACKET  Sequenced, reliable, two-way, connection-based data transmission path for datagrams of fixed maximum length (SCTP)
            SOCK_RAW        Raw network protocol access (Transport layer protocols not required)            
        protocol: specifies a protocol to be used with the socket. Normally, only a single
                  protocol exists to support a particular socket type within a given family(as specified within
                  parenthese above). In such cases, this argument is 0.
bind()
    With the call to socket(), a socket is created, but no address is assigned to it.
    bind() is used to bind the socket descriptor sockfd with the address addr; and addrlen
    is its length. This is called assigning a name to the socket.
    int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
listen()
    The listen() call marks the socked referred to by sockfd as a passive socket - one
    the will be used to accept incoming connections. The socket type should be SOCK_STREAM or SOCK_SEQPACKET, i.e., a realiable connection.
    The backlog argument defines the maximum length of the queue of pending connections for sockfd. If the queue grows
    above this, connections will be refused by clients.
    int listen(int sockfd, int backlog);
accept()
    accept() call create another socket descriptor for the client. Now, whatever is written to this
    descriptor is sent to the client, and whatever is read from this descriptor is the data the client
    sent to the server. The accept() system call is used with socket types SOCK_STREAM and SOCK_SEQPACKET.
    It extracts the first connection request on the queue of pending connections for the listening socket sockfd,
    creates a new connected socket, and returns a new descriptor referring to that socket.
    The newly created socket is not int the listening state. The original socket sockfd si unaffected
    by this call. The addr argument contains the address of the remote machine to which we connect; since we don't know
    the client's address in advance, it's NULL here. The addrlen argument is the length of addr - so, again, this is NULL.
    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
read()
    let us read a character(sent by the client to the server) from the descriptor
write()
    let us write to the descriptor, to send the character to the client
close()
    close the descriptor

*/