/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/30 19:40:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	exec_cmd_bonus(t_pipex *data, int pos)
{
	char	*path;
	char	**cmd_arr;

	cmd_arr = ft_split(data->argv[2 + data->here_doc + pos], ' ');
	path = get_path(cmd_arr[0], data->envp);
	if (!path)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("Command '%s' not found.\n", cmd_arr[0]);
		clean_pipex_exit(data, NULL, EXIT_FAILURE);
	}
	if (execve(path, cmd_arr, data->envp) < 0)
		clean_pipex_exit(data, EXECVE_FAIL_MSG, EXIT_FAILURE);
}

int	wait_children_bonus(t_pipex *data)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	while (i < data->cmd_count)
	{
		waitpid(data->pid_arr[i], &status, 0);
		if (i == data->cmd_count - 1)
		{
			if (WIFEXITED(status))
				last_status = (WEXITSTATUS(status));
			else
				last_status = EXIT_FAILURE;
		}
		i++;
	}
	return (last_status);
}

void	close_unused_pipes(t_pipex *data, int pos)
{
	int	i;

	i = 0;
	while (i < data->cmd_count)
	{
		if (i != pos - 1)
			close(data->pipeline[i][0]);
		if (i != pos)
			close(data->pipeline[i][1]);
		i++;
	}
}

static void	exec_firstchild_bonus(t_pipex *data)
{
	int	read_end;
	
	read_end = open(data->argv[1 + data->here_doc], O_RDONLY);
	if (read_end < 0)
		clean_pipex_exit(data, OPEN_FAIL_MSG, EXIT_FAILURE);
	close_unused_pipes(data, 0);
	dup2(read_end, STDIN_FILENO);
	close(read_end);
	dup2(data->pipeline[0][1], STDOUT_FILENO);
	close(data->pipeline[0][1]);
	exec_cmd_bonus(data, 0);
}

static void	exec_midlechild_bonus(t_pipex *data, int pos)
{
	close_unused_pipes(data, pos);
	dup2(data->pipeline[pos - 1][0], STDIN_FILENO);
	close(data->pipeline[pos - 1][0]);
	dup2(data->pipeline[pos][1], STDOUT_FILENO);
	close(data->pipeline[pos][1]);
	exec_cmd_bonus(data, pos);
}
static void exec_lastchild_bonus(t_pipex *data, int pos)
{
	int	write_end;

	write_end = open(data->argv[pos], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (write_end < 0)
		clean_pipex_exit(data, OPEN_FAIL_MSG, EXIT_FAILURE);
	close_unused_pipes(data, pos);
	dup2(data->pipeline[pos - 1][0], STDIN_FILENO);
	close(data->pipeline[pos - 1][0]);
	dup2(write_end, STDOUT_FILENO);
	close(write_end);
	exec_cmd_bonus(data, pos);
}
void	exec_child(t_pipex *data, int pos)
{
	if (pos == 0)
		exec_firstchild_bonus(data);
	else if (pos == (data->cmd_count - 1))
		exec_lastchild_bonus(data, pos);
	else if (pos > 0 && pos < data->cmd_count)
		exec_midlechild_bonus(data, pos);
}
