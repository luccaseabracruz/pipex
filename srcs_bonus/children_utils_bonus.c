/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/04 20:32:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//delete 
void	print_lines(int fd);

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
		clean_error_exit(data, NULL, EXIT_FAILURE);
	}
	if (execve(path, cmd_arr, data->envp) == -1)
		clean_error_exit(data, EXECVE_FAIL_MSG, EXIT_FAILURE);
}

int	wait_children_bonus(t_pipex *data)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	last_status = EXIT_FAILURE;
	while (i < data->cmd_count)
	{
		waitpid(data->pid_arr[i], &status, 0);
		if ((i == data->cmd_count - 1) && WIFEXITED(status))
			last_status = (WEXITSTATUS(status));
		i++;
	}
	return (last_status);
}

void	close_unused_pipes(t_pipex *data, int pos)
{
	int	i;

	i = 0;
	if (pos != 0)
		close(data->fds[0]);
	if (pos != (data->cmd_count - 1))
		close(data->fds[1]);
	while (i < data->cmd_count - 1)
	{
		if (i != pos - 1)
			close(data->pipeline[i][0]);
		if (i != pos)
			close(data->pipeline[i][1]);
		i++;
	}
}

void	exec_child(t_pipex *data, int pos)
{
	close_unused_pipes(data, pos);
	if (pos == 0)
	{
		dup2(data->fds[0], STDIN_FILENO);
		close(data->fds[0]);
	}
	else
	{
		dup2(data->pipeline[pos - 1][0], STDIN_FILENO);
		close(data->pipeline[pos - 1][0]);
	}
	if (pos == (data->cmd_count - 1))
	{
		dup2(data->fds[1], STDOUT_FILENO);
		close(data->fds[1]);
	}
	else
	{
		dup2(data->pipeline[pos][1], STDOUT_FILENO);
		close(data->pipeline[pos][1]);
	}
	exec_cmd_bonus(data, pos);
}
