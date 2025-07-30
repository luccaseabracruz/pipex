/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/30 19:40:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdbool.h>
# include <sys/types.h>

# define HERE_DOC "here_doc"

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		**pipeline;
	pid_t	*pid_arr;
	int		cmd_count;
	bool	here_doc;
}			t_pipex;

void	init_data(t_pipex *data, int argc, char **argv, char **envp);
void	close_free_pipes(int **pipes, int size);
void	clean_pipex(t_pipex *data);
void	clean_pipex_exit(t_pipex *data, char *msg, int status);
void	exec_child(t_pipex *data, int pos);
int		wait_children_bonus(t_pipex *data);

#endif