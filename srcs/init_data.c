/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:28:32 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/14 17:05:06 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/includes/libft.h"

void	init_data(t_pipex *data, char **argv, char **envp)
{
	ft_bzero(data, sizeof(t_pipex));
	data->argv = argv;
	data->envp = envp;
	if (pipe(data->pipefd) < 0)
		puterr_exit(PIPE_FAIL_MSG, EXIT_FAILURE);
	data->fds[0] = open(argv[1], O_RDONLY);
	if (data->fds[0] < 0)
	{
		close_pipe(data->pipefd);
		puterr_exit(argv[1], EXIT_FAILURE);
	}
	data->fds[1] = open(argv[4], (O_WRONLY | O_CREAT | O_TRUNC), 0644);
	if (data->fds[0] < 0)
	{
		close(data->fds[0]);
		close_pipe(data->pipefd);
		puterr_exit(argv[1], EXIT_FAILURE);
	}
}
