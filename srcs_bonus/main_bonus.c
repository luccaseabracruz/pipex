/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:33:57 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/14 17:36:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex_bonus	data;
	int				i;
	int				exit_status;

	if (argc < 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	init_data_bonus(&data, argc, argv, envp);
	i = 0;
	while (i < data.cmd_count)
	{
		data.pid_arr[i] = fork();
		if (data.pid_arr[i] < 0)
			clean_error_exit(&data, FORK_FAIL_MSG, EXIT_FAILURE);
		if (data.pid_arr[i] == 0)
			exec_child_bonus(&data, i);
		i++;
	}
	close_pipes(data.pipeline, (data.cmd_count - 1));
	close_pipe(data.fds);
	exit_status = wait_children_bonus(&data);
	pipex_final_clean(&data);
	return (exit_status);
}
