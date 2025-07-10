/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:33:33 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 11:51:00 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_readline(int fd, char *line, char *buffer)
{
	int	bytes_read;

	while (!ft_findlinebreak(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_bufferlinejoin_bonus(line, buffer);
	}
	return (line);
}

int	ft_findlinebreak(char	*str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strlen_chr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (str && str[i] == c)
		i++;
	return (i);
}

char	*ft_bufferlinejoin_bonus(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	char	*res;

	line_len = ft_strlen_chr(line, '\n');
	buffer_len = ft_strlen_chr(buffer, '\n');
	res = malloc((line_len + buffer_len + 1) * sizeof(char));
	if (!res)
	{
		free(line);
		ft_clean_buffer_bonus(buffer);
		return (NULL);
	}
	res[line_len + buffer_len] = '\0';
	buffer_len++;
	while (--buffer_len > 0)
		res[line_len + buffer_len - 1] = buffer[buffer_len - 1];
	line_len++;
	while (--line_len > 0)
		res[line_len - 1] = line[line_len - 1];
	free(line);
	return (res);
}

void	ft_clean_buffer_bonus(char *buffer)
{
	size_t	buffer_len;
	size_t	i;

	buffer_len = ft_strlen_chr(buffer, '\n');
	i = 0;
	while (buffer[i + buffer_len])
	{
		buffer[i] = buffer[i + buffer_len];
		i++;
	}
	while (buffer[i])
		buffer[i++] = '\0';
}
