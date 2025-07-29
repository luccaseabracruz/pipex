/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/29 20:06:56 by lseabra-         ###   ########.fr       */
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

void	init_data(t_pipex *pipex_data, int argc, char **argv, char **envp);
void	close_free_pipes(int **pipes, int size);
void	clean_pipex_exit(t_pipex *pipex_data, char *msg, int status);
int		wait_all_children(t_pipex *pipex_data);

#endif