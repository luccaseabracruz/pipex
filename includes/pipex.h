/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:10:58 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/18 16:15:14 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PROGRAM_NAME "pipex"
# define PATH "PATH="
# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define NO_FILE_OR_DIR_MSG "no such file or directory"
# define CMD_NOT_FOUND_MSG "command not found"
# define FORK_FAIL_MSG "fork"
# define OPEN_FAIL_MSG "open"
# define DUP2_FAIL_MSG "dup2"
# define PIPE_FAIL_MSG "pipe"
# define EXECVE_FAIL_MSG "lalalala"
# define PATH_FAIL_MSG "Could not find a valid path"
# define EXIT_INVALID_INPUT 3
# define EXIT_NOT_FOUND 127
# define TRUE 1
# define FALSE 0

# include <sys/types.h>

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		fds[2];
	int		pipefd[2];
	pid_t	pid_arr[2];
}			t_pipex;

void	init_data(t_pipex *data, char **argv, char **envp);
int		wait_children(pid_t pid_arr[2]);
void	puterr_exit(const char *msg, int status);
void	close_fds(int fds[2]);
void	free_strarr(char **arr);
void	dup2_close(int oldfd, int newfd);
char	*get_path(char *cmd, char **envp);
void	exec_child(t_pipex *data, int child_index);

#endif