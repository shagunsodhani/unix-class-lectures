#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int main(int argc, char **argv)
{
	int		fd, i;
	char	*ptr;
	size_t	filesize, mmapsize, pagesize;

	mmapsize = 2000;
	filesize = 2000;

		/* 4open file: create or truncate; set file size */
	fd = open("test.data", O_RDWR | O_CREAT | O_TRUNC, 0666);
	
	lseek(fd, filesize-1, SEEK_SET);
	
	write(fd, "", 1);

	ptr = mmap(NULL, mmapsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	close(fd);

	pagesize = sysconf(_SC_PAGESIZE);
	printf("PAGESIZE = %ld\n", (long) pagesize);

	for (i = 0; i < max(filesize, mmapsize); i += pagesize) {
		printf("ptr[%d] = %d\n", i, ptr[i]);
		ptr[i] = 1;
		printf("ptr[%d] = %d\n", i + pagesize - 1, ptr[i + pagesize - 1]);
		ptr[i + pagesize - 1] = 1;
	}
	printf("ptr[%d] = %d\n", i, ptr[i]);
	printf("ptr[%d] = %d\n", i+1, ptr[i+1]);
	exit(0);
}
