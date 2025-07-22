/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:43:08 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/22 16:12:13 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

static char	*find_valid_path(char **all_paths, char *cmd)
{
	char	*dir_path;
	char	*complete_path;
	int		i;

	i = 0;
	while (all_paths[i])
	{
		dir_path = ft_strjoin(all_paths[i], "/");
		complete_path = ft_strjoin(dir_path, cmd);
		free(dir_path);
		if (access(complete_path, F_OK | X_OK) == 0)
			return (complete_path);
		free(complete_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*valid_path;
	int		i;

	if (!cmd || !envp)
		return (NULL);
	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], PATH, ft_strlen(PATH)))
		i++;
	if (!envp[i])
		return (NULL);
	all_paths = ft_split((envp[i] + ft_strlen(PATH)), ':');
	valid_path = find_valid_path(all_paths, cmd);
	free_strarr(all_paths);
	return (valid_path);
}
