/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:38 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/18 11:50:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	init_pipeline(t_pipex_bonus *data)
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

static bool	is_strline_equal(char *str, char *line)
{
	size_t	len;

	if (ft_strlen(str) > (ft_linelen(line) - 1))
		len = ft_strlen(str);
	else
		len = (ft_linelen(line) - 1);
	if (ft_strncmp(str, line, len) == 0)
		return (TRUE);
	else
		return (FALSE);
}

static void	exec_here_doc(t_pipex_bonus *data)
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
		else if (is_strline_equal(data->argv[2], line))
			break ;
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	if (line)
		free(line);
	close(pipefd[1]);
	data->fds[0] = pipefd[0];
}

static void	init_file_fds(t_pipex_bonus *data)
{
	char	*outfile;

	outfile = data->argv[data->argc - 1];
	if (data->here_doc)
	{
		exec_here_doc(data);
		data->fds[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->fds[1] < 0)
		{
			close(data->fds[0]);
			clean_error_exit(data, outfile, EXIT_FAILURE);
		}
	}
	else
	{
		data->fds[0] = open(data->argv[1], O_RDONLY);
		if (data->fds[0] < 0)
			clean_error_exit(data, data->argv[1], EXIT_FAILURE);
		data->fds[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fds[1] < 0)
		{
			close(data->fds[0]);
			clean_error_exit(data, outfile, EXIT_FAILURE);
		}
	}
}

void	init_data_bonus(t_pipex_bonus *dt, int argc, char **argv, char **envp)
{
	ft_bzero(dt, sizeof(t_pipex_bonus));
	dt->fds[0] = -1;
	dt->fds[1] = -1;
	dt->argc = argc;
	dt->argv = argv;
	dt->envp = envp;
	if (ft_strncmp(HERE_DOC, argv[1], ft_strlen(HERE_DOC) + 1) == 0)
		dt->here_doc = TRUE;
	dt->cmd_count = argc - 3 - dt->here_doc;
	init_file_fds(dt);
	dt->pid_arr = ft_calloc(dt->cmd_count, sizeof(int));
	if (!dt->pid_arr)
		clean_error_exit(dt, NULL, EXIT_FAILURE);
	init_pipeline(dt);
}
