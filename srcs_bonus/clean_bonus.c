/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:19 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/30 21:49:10 by lseabra-         ###   ########.fr       */
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

void	clean_pipex(t_pipex *data)
{
	if (data->pipeline)
		close_free_pipes(data->pipeline, data->cmd_count - 1);
	if (data->pid_arr)
		free(data->pid_arr);
}

void	clean_pipex_exit(t_pipex *data, char *msg, int status)
{
	clean_pipex(data);
	if (msg)
		puterr_exit(msg, status);
	exit(status);
}
