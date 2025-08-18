/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:04:23 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/18 16:03:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	exec_cmd(t_pipex *data, int child_index)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(data->argv[2 + child_index], ' ');
	path = get_path(cmd_arr[0], data->envp);
	if (!path)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("%s: %s: %s\n", PROGRAM_NAME, CMD_NOT_FOUND_MSG, cmd_arr[0]);
		free_strarr(cmd_arr);
		close_pipe(data->pipefd);
		close_pipe(data->fds);
		exit(EXIT_NOT_FOUND);
	}
	if (execve(path, cmd_arr, data->envp) < 0)
	{
		free_strarr(cmd_arr);
		close_pipe(data->pipefd);
		close_pipe(data->fds);
		puterr_exit(EXECVE_FAIL_MSG, EXIT_FAILURE);
	}
}

void	exec_child(t_pipex *data, int child_index)
{
	if (child_index == 0)
	{
		if (data->fds[0] < 0)
			exit(EXIT_FAILURE);
		close(data->pipefd[0]);
		dup2_close(data->fds[0], STDIN_FILENO);
		dup2_close(data->pipefd[1], STDOUT_FILENO);
	}
	else if (child_index == 1)
	{
		close(data->pipefd[1]);
		dup2_close(data->pipefd[0], STDIN_FILENO);
		dup2_close(data->fds[1], STDOUT_FILENO);
	}
	exec_cmd(data, child_index);
}
