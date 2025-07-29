/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:38 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 17:22:46 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	init_pipeline(t_pipex *data)
{
	int	i;

	data->pipeline = ft_calloc((data->cmd_count - 1), sizeof(int *));
	if (!data->pipeline)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < (data->cmd_count - 1))
	{
		data->pipeline[i] = ft_calloc(2, sizeof(int));
		if (!data->pipeline[i])
		{
			close_free_pipes(data->pipeline, i);
			exit(EXIT_FAILURE);
		}
		else if (pipe(data->pipeline[i]) == -1)
		{
			free(data->pipeline[i]);
			close_free_pipes(data->pipeline, i);
			puterr_exit(PIPE_FAIL_MSG, EXIT_FAILURE);
		}
		i++;
	}
}

static void	init_pid_arr(t_pipex *data)
{
	int	i;

	i = 0;
	data->pid_arr = ft_calloc(data->cmd_count, sizeof(int *));
	if (!data->pid_arr)
		clean_pipex_exit(data, NULL, EXIT_FAILURE);
	while (i < data->cmd_count)
	{
		data->pid_arr[i] = ft_calloc(1, sizeof(int));
		if (!data->pid_arr[i])
		{
			free_intarr(data->pid_arr, i);
			clean_pipex_exit(data, FORK_FAIL_MSG, EXIT_FAILURE);
		}
		i++;
	}
}

void	init_data(t_pipex *pipex_data, int argc, char **argv, char **envp)
{
	ft_bzero(pipex_data, sizeof(t_pipex));
	pipex_data->argv = argv;
	pipex_data->envp = envp;
	pipex_data->cmd_count = argc - 3;
	if (ft_strnstr(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
	{
		pipex_data->cmd_count--;
		pipex_data->here_doc = TRUE;
		ft_putstr_fd("here_doc not implemented yet....", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	init_pipeline(pipex_data);
	init_pid_arr(pipex_data);
}
