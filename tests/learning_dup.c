#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// int	main(void)
// {
// 	int	fd1;

// 	fd1 = open("file1.txt", O_WRONLY);
// 	if (fd1 < 0)
// 	{
// 		perror("open failed.");
// 		exit(1);
// 	}
// 	if (dup2(fd1, 1) < 0)
// 	{
// 		perror("dup2 fail.");
// 		exit(1);
// 	}
// 	printf("It worked! I know how to replace STDOUT.");
// }
