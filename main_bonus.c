/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:33:57 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/28 13:28:54 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./includes/pipex_bonus.h"
#include "./libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	init_pipes(t_pipex *pipex_data)
{
	int	i;

	pipex_data->pipeline = ft_calloc(pipex_data->cmd_count, sizeof(int *));
	if (!pipex_data->pipeline)
		return (EXIT_FAILURE);
	i = 0;
	while (i < pipex_data->cmd_count)
	{
		pipex_data->pipeline[i] = ft_calloc(2, sizeof(int));
		if (!pipex_data->pipeline[i])
		{
			close_free_pipes(pipex_data->pipeline, i);
			exit(EXIT_FAILURE);
		}
		else if (pipe(pipex_data->pipeline[i]) == -1)
		{
			free(pipex_data->pipeline[i]);
			close_free_pipes(pipex_data->pipeline, i);
			puterror_exit(PIPE_FAIL_MSG, EXIT_FAILURE);
		}
		i++;
	}
}

void	init_data(t_pipex *pipex_data, int argc, char **argv, char **envp)
{
	ft_bzero(pipex_data, sizeof(t_pipex));
	pipex_data->argv = argv;
	pipex_data->envp = envp;
	pipex_data->cmd_count = argc - 3;
	if (ft_strnstr(argv[1], HERE_DOC, ft_strlen(HERE_DOC)) == 0)
	{
		pipex_data->cmd_count--;
		pipex_data->here_doc = TRUE;
		//DELETE
		ft_putstr_fd("here_doc not implemented yet....", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	init_pipes(pipex_data->pipeline);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex_data;

	if (argc < 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	init_data(&pipex_data, argc, argv, envp);
	
}
