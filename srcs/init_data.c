/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:28:32 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/18 15:58:09 by lseabra-         ###   ########.fr       */
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
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("%s: %s: %s\n", PROGRAM_NAME, NO_FILE_OR_DIR_MSG, argv[1]);
	}
	data->fds[1] = open(argv[4], (O_WRONLY | O_CREAT | O_TRUNC), 0644);
	if (data->fds[1] < 0)
		perror(OPEN_FAIL_MSG);
}
