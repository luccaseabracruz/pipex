/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:23:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/21 18:06:04 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int		pipefd[2];
	int		pid;
	char	*buffer;

	if (pipe(pipefd) < 0)
	{
		perror("pipe failed.");
		exit(1);
	}
	printf("pid before fork: %d\n", getpid());
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed.");
		exit(1);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		printf("Inside Child process with pid %d as return (not its pid).\n", pid);
		printf("Child process with real pid: %d.\n", getpid());
		write(pipefd[1], "Writing from child\n", strlen("Writing from child\n"));
		write(pipefd[1], "This is a second line\n", strlen("This is a second line\n"));
		close(pipefd[1]);
	}
	else if (pid > 0)
	{
		close(pipefd[1]);
		printf("Inside the Parent Process with pid %d as return (its the child pid)\n", pid);
		printf("Parent real pid: %d.\n", getpid());
		buffer = get_next_line_bonus(pipefd[0]);
		while (buffer)
		{
			printf("print line of pipefd[0]: %s", buffer);
			free(buffer);
			buffer = get_next_line_bonus(pipefd[0]);
		}
		close(pipefd[0]);
		wait(NULL);
	}
}
