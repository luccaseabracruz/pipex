/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:01:03 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memset - Fills a block of memory with a specified value.
 * @param s: Pointer to the memory block to fill.
 * @param c: The value to set.
 * @param n: The number of bytes to fill.
 *
 * @return A pointer to the memory block.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int s[] = {'2', '7', '4', '\0'};
	char c = 'c';
	size_t n = 3;
	
	printf("s: %s\nc: %c\nn: %zd\n	new s: %s", s, c, ft_memset(s, c, n), s);
}
*/
