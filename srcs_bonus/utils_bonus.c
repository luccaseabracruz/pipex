/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:19 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/28 13:19:30 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <stdlib.h>

void	close_free_pipes(int **pipes, int size)
{
	while (--size >= 0)
	{
		close_pipe(pipes[size]);
		free(pipes[size]);
	}
	free(pipes);
}
