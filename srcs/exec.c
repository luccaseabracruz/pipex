/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:04:23 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/23 14:50:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	exec_command(int pipefd[2], char *cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	path = get_path(cmd_arr[0], envp);
	if (!path)
	{
		if (dup2(STDERR_FILENO, STDOUT_FILENO) == -1)
		{
			free_strarr(cmd_arr);
			puterr_exit(DUP2_FAIL_MSG, EXIT_FAILURE);
		}
		ft_printf("Command '%s' not found.\n", cmd_arr[0]);
		free_strarr(cmd_arr);
		close_pipe(pipefd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		free_strarr(cmd_arr);
		close_pipe(pipefd);
		puterr_exit(EXECVE_FAIL_MSG, EXIT_FAILURE);
	}
}

void	exec_firstchild(char **argv, char **envp, int pipefd[2])
{
	int	read_end;

	close(pipefd[0]);
	read_end = open(argv[1], O_RDONLY);
	if (read_end == -1)
	{
		close(pipefd[1]);
		puterr_exit(argv[1], EXIT_FAILURE);
	}
	dup2(read_end, STDIN_FILENO);
	close(read_end);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_command(pipefd, argv[2], envp);
}

void	exec_secondchild(char **argv, char **envp, int pipefd[2])
{
	int	write_end;

	close(pipefd[1]);
	write_end = open(argv[4], (O_WRONLY | O_CREAT | O_TRUNC), 0644);
	if (write_end == -1)
	{
		close(pipefd[1]);
		puterr_exit(OPEN_FAIL_MSG, EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(write_end, STDOUT_FILENO);
	close(write_end);
	exec_command(pipefd, argv[3], envp);
}
