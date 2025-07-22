#include "../libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		execve("/bin/ls", argv, envp);
		perror(NULL);
	}
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	char	**str_arr;
// 	char	sep;
// 	int		i;

// 	if (argc > 1)
		
// 	return (0);
// }