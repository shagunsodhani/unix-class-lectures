#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024


int main()
{
    int fd[2];
    char * myfifo = "/tmp/myfifo";
    char* str = "message\0" ;
    char buf[MAX_BUF];

	mkfifo(myfifo, 0666);
	fd[1] = open(myfifo, O_RDONLY );
    fd[0] = open(myfifo, O_WRONLY );
    //fd[0] = open(myfifo, O_WRONLY | O_NONBLOCK, 0 );
    // fd[0] = open(myfifo, O_WRONLY | O_NONBLOCK, 0 );

	write(fd[0], str, 15);
	
	read(fd[1], buf, MAX_BUF);
	printf("Received: %s\n", buf);
	
	close(fd[0]);
	close(fd[1]);
	unlink(myfifo);

    return 0;
    
}
