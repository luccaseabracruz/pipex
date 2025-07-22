/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:10:58 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/21 21:51:26 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PATH "PATH="
# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define OPEN_FAIL_MSG "open() sys call fail"
# define FORK_FAIL_MSG "fork() sys call fail"
# define DUP2_FAIL_MSG "dup2() sys call fail"
# define PIPE_FAIL_MSG "pipe() sys call fail"
# define EXECVE_FAIL_MSG "execve() sys call fail"
# define PATH_FAIL_MSG "Could not find a valid path"
# define EXIT_INVALID_INPUT 3
# define EXIT_NOT_FOUND 127

# include <sys/types.h>

int		wait_children(pid_t pid1, pid_t pid2);
void	puterr_exit(const char *msg, int code);
void	close_pipe(int pipefd[2]);
void	free_strarr(char **arr);
char	*get_path(char *cmd, char **envp);
void	exec_firstchild(char **argv, char **envp, int pipefd[2]);
void	exec_secondchild(char **argv, char **envp, int pipefd[2]);

#endif