/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:19 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 19:39:04 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	close_free_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close_pipe(pipes[i]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	clean_pipex_exit(t_pipex *pipex_data, char *msg, int status)
{
	if (pipex_data->pipeline)
		close_free_pipes(pipex_data->pipeline, (pipex_data->cmd_count - 1));
	if (pipex_data->pid_arr)
		free(pipex_data->pid_arr);
	if (msg)
		puterr_exit(msg, status);
	exit(status);
}
