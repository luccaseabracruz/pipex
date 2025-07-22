#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"
#include "../libft/includes/libft.h"

// int	main(int argc, char **argv)
// {
// 	if (argc != 5)
// 	{
// 		ft_putstr_fd("Error: Invalid Input.\n", STDERR_FILENO);
// 		exit(EXIT_INVALID_INPUT);
// 	}
// 	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
// 		perror(argv[1]);
// 	if (access(argv[4], F_OK) == -1 || access(argv[4], W_OK) == -1)
// 		perror(argv[4]);
// 	return (0);
// }