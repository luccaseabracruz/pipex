/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:33:57 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 20:04:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./includes/pipex_bonus.h"
#include "./libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex_data;
	int		i;

	if (argc < 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	init_data(&pipex_data, argc, argv, envp);
	i = 0;
	while (i < pipex_data.cmd_count)
	{
		pipex_data.pid_arr[i] = fork();
		if (pipex_data.pid_arr[i] == EXIT_FAILURE)
			clean_pipex_exit(&pipex_data, FORK_FAIL_MSG, EXIT_FAILURE);
		if (pipex_data.pid_arr[i] == 0)
		{
			ft_printf("Inside children %d with pid %d\n", i, getpid());
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	ft_printf("END\n");
	clean_pipex_exit(&pipex_data, NULL, EXIT_SUCCESS);
	return (wait_all_children(&pipex_data));
}
