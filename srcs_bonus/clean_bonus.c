/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:19 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/18 16:16:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	close_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	close_free_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close_fds(pipes[i]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	clean_error_exit(t_pipex_bonus *data, char *msg, int status)
{
	if (data->pipeline)
		close_free_pipes(data->pipeline, data->cmd_count - 1);
	if (data->fds[0] > 2)
		close(data->fds[0]);
	if (data->fds[1] > 2)
		close(data->fds[1]);
	if (data->pid_arr)
		free(data->pid_arr);
	if (msg)
		puterr_exit(msg, status);
	exit(status);
}

void	pipex_final_clean(t_pipex_bonus *data)
{
	int	i;

	if (data->pipeline)
	{
		i = 0;
		while (i < (data->cmd_count - 1))
		{
			free(data->pipeline[i]);
			i++;
		}
		free(data->pipeline);
	}
	if (data->pid_arr)
		free(data->pid_arr);
}
