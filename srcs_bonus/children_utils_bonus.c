/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 20:32:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	wait_all_children(t_pipex *pipex_data)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipex_data->cmd_count)
	{
		waitpid(pipex_data->pid_arr[i], &status, 0);
		if (!(WIFEXITED(status)))
			clean_pipex_exit(pipex_data, NULL, EXIT_FAILURE);
		i++;
	}
	return (WEXITSTATUS(status));
}

void	exec_child(t_pipex *data, int pos)
{
	int	fd;

	if (pos == 0)
	{
		fd = open(data->argv[1 + data->here_doc], O_RDONLY);
		if (fd == -1)
			clean_pipex_exit(data, OPEN_FAIL_MSG, EXIT_FAILURE);
		close(data->pipeline[pos][0]);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(data->pipeline[pos][1], STDOUT_FILENO);
		close(data->pipeline[pos][1]);
		execve()
	}
	else if (pos == data->cmd_count - 1)
	{
		//todo: implement last children
	}
	else
	{
		//todo: implement children in midle
	}
}