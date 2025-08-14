/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/14 19:47:00 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdbool.h>
# include <sys/types.h>

# define HERE_DOC "here_doc"
# define HERE_DOC_PREFIX "\033[1;37m heredoc> \033[0m"
# define HERE_DOC_WARNING "warning: here-document delimited by end-of-file"
# define DUP_FAIL_MSG "dup"

typedef struct s_pipex_bonus
{
	int		argc;
	char	**argv;
	char	**envp;
	int		fds[2];
	int		**pipeline;
	pid_t	*pid_arr;
	int		cmd_count;
	bool	here_doc;
}			t_pipex_bonus;

void	init_data_bonus(t_pipex_bonus *dt, int argc, char **argv, char **envp);
void	close_pipes(int **pipes, int size);
void	close_free_pipes(int **pipes, int size);
void	clean_error_exit(t_pipex_bonus *data, char *msg, int status);
void	pipex_final_clean(t_pipex_bonus *data);
void	exec_child_bonus(t_pipex_bonus *data, int pos);
int		wait_children_bonus(t_pipex_bonus *data);

#endif