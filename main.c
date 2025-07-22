/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:12:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/21 20:08:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include <sys/types.h>

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	if (pipe(pipefd) == -1)
		puterr_exit(PIPE_FAIL_MSG, EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		puterr_exit(FORK_FAIL_MSG, EXIT_FAILURE);
	if (pid1 == 0)
		exec_firstchild(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		puterr_exit(FORK_FAIL_MSG, EXIT_FAILURE);
	if (pid2 == 0)
		exec_secondchild(argv, envp, pipefd);
	close_pipe(pipefd);
	return (wait_children(pid1, pid2));
}
