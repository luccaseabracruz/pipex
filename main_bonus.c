/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:33:57 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 16:42:32 by lseabra-         ###   ########.fr       */
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

	if (argc < 5)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		exit(EXIT_INVALID_INPUT);
	}
	init_data(&pipex_data, argc, argv, envp);
	ft_printf("Ending programm\n");
	clean_pipex_exit(&pipex_data, NULL, EXIT_SUCCESS);
}
