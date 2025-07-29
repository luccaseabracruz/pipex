/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:38 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 19:38:29 by lseabra-         ###   ########.fr       */
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
			clean_pipex_exit(data, NULL, EXIT_FAILURE);
		}
		else if (pipe(data->pipeline[i]) == -1)
		{
			free(data->pipeline[i]);
			close_free_pipes(data->pipeline, i);
			clean_pipex_exit(data, PIPE_FAIL_MSG, EXIT_FAILURE);
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
	pipex_data->pid_arr = ft_calloc(pipex_data->cmd_count, sizeof(int));
	if (!pipex_data->pid_arr)
		clean_pipex_exit(pipex_data, NULL, EXIT_FAILURE);
	if (ft_strnstr(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
	{
		pipex_data->cmd_count--;
		pipex_data->here_doc = TRUE;
		ft_printf("here_doc not implemented yet.... please comeback later\n");
		clean_pipex_exit(pipex_data, NULL, EXIT_FAILURE);
	}
	init_pipeline(pipex_data);
}
