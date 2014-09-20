#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
	int		fd, i, nloop, zero = 0;
	int		*ptr;

	fd = open("/tmp/temp.1", O_RDWR | O_CREAT, 0666);
// 
	// fd = open("/dev/zero", O_RDWR, 0666);
	printf("passed\n");
	i = 0;
	write(fd, &i, sizeof(int));

	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	close(fd);

	printf("passed again\n");

	if (fork() == 0) 
	{
		printf("child: %d\n", (*ptr) );	
		/* child */
		printf("child: %d\n", (*ptr)++ );
		exit(0);
	}

		/* 4parent */
	sleep(2);
	printf("parent: %d\n", (*ptr)++);
	// munmap(ptr, sizeof(int));
	// unlink("/tmp/temp.1");
	exit(0);
}
