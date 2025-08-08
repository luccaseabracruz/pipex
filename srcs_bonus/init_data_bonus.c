/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:38 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/07 19:52:09 by lseabra-         ###   ########.fr       */
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

static void	exec_here_doc(t_pipex *data)
{
	char	*line;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		puterr_exit(PIPE_FAIL_MSG, EXIT_FAILURE);
	while (TRUE)
	{
		ft_putstr_fd(HERE_DOC_PREFIX, STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_printf("\n%s (wanted `%s')\n", HERE_DOC_WARNING, data->argv[2]);
			break ;
		}
		else if (ft_strncmp(data->argv[2], line, (ft_linelen(line)) - 1) == 0)
			break ;
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	if (line)
		free(line);
	close(pipefd[1]);
	data->fds[0] = pipefd[0];
}

static void	init_file_fds(t_pipex *data, int argc, char **argv)
{
	if (data->here_doc)
		exec_here_doc(data);
	else
	{
		data->fds[0] = open(argv[1], O_RDONLY);
		if (data->fds[0] < 0)
			clean_error_exit(data, argv[1], EXIT_FAILURE);
	}
	data->fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fds[1] < 0)
	{
		close(data->fds[0]);
		clean_error_exit(data, argv[argc - 1], EXIT_FAILURE);
	}
}

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	ft_bzero(data, sizeof(t_pipex));
	data->fds[0] = -1;
	data->fds[1] = -1;
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	if (ft_strnstr(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
		data->here_doc = TRUE;
	data->cmd_count = argc - 3 - data->here_doc;
	init_file_fds(data, argc, argv);
	data->pid_arr = ft_calloc(data->cmd_count, sizeof(int));
	if (!data->pid_arr)
		clean_error_exit(data, NULL, EXIT_FAILURE);
	init_pipeline(data);
}
