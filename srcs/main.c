/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:12:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/14 17:24:23 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <sys/types.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		i;

	if (argc != 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	init_data(&data, argv, envp);
	i = 0;
	while (i < 2)
	{
		data.pid_arr[i] = fork();
		if (data.pid_arr[i] < 0)
		{
			close_pipe(data.fds);
			puterr_exit(FORK_FAIL_MSG, EXIT_FAILURE);
		}
		if (data.pid_arr[i] == 0)
			exec_child(&data, i);
		i++;
	}
	close_pipe(data.pipefd);
	close_pipe(data.fds);
	return (wait_children(data.pid_arr));
}
