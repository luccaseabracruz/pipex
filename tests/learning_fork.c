/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:27:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/15 09:10:05 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if(pid < 0)
	{
		perror("fork failed.");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("Inside child proccess with pid = %d\n", pid);
	}
	else
	{
		printf("Inside parent proccess with pid = %d\n", pid);
	}
	return (0);
}
