/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:38 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/04 19:29:47 by lseabra-         ###   ########.fr       */
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
			clean_error_exit(data, NULL, EXIT_FAILURE);
		}
		else if (pipe(data->pipeline[i]) < 0)
		{
			free(data->pipeline[i]);
			close_free_pipes(data->pipeline, i);
			clean_error_exit(data, PIPE_FAIL_MSG, EXIT_FAILURE);
		}
		i++;
	}
}

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	ft_bzero(data, sizeof(t_pipex));
	data->fds[0] = open(argv[1 + data->here_doc], O_RDONLY);
	if (data->fds[0] < 0)
		puterr_exit(argv[1 + data->here_doc], EXIT_FAILURE);
	data->fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fds[1] < 0)
	{
		close(data->fds[0]);
		puterr_exit(argv[argc - 1], EXIT_FAILURE);
	}
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->cmd_count = argc - 3;
	data->pid_arr = ft_calloc(data->cmd_count, sizeof(int));
	if (!data->pid_arr)
		clean_error_exit(data, NULL, EXIT_FAILURE);
	if (ft_strnstr(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
	{
		data->cmd_count--;
		data->here_doc = TRUE;
		ft_printf("here_doc not implemented yet.... please comeback later\n");
		clean_error_exit(data, NULL, EXIT_FAILURE);
	}
	init_pipeline(data);
}
