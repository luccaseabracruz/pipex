/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:44 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 11:52:34 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_linelen(char *s);
char	*ft_bufferlinejoin(char *line, char *buffer);
int		ft_haschr(char *s, int c);
void	ft_cleanbuffer(char *buffer);

#endif