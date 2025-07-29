/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/28 12:53:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <stdbool.h>

# define HERE_DOC "here_doc"



typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		**pipeline;
	int		cmd_count;
	bool	here_doc;
}			t_pipex;

void	init_pipes(int **pipes);

#endif