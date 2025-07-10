/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:30:42 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memcpy - Copies memory from one location to another.
 * @param dst: Pointer to the destination memory block.
 * @param src: Pointer to the source memory block.
 * @param n: The number of bytes to copy.
 *
 * @return A pointer to the destination memory block.
 * @note The memory areas must not overlap.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_cp;
	char	*src_cp;

	i = 0;
	dest_cp = (char *)dest;
	src_cp = (char *)src;
	if (dest_cp == NULL && src_cp == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		dest_cp[i] = src_cp[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	// char	src[9] = "Seabra";
	// char	dest[6] = "Lucca";
	char	*src = NULL;
	char	*dest = NULL;
	// char	*mysrc = NULL;
	// char	*mydest = "Lucca";
	
	// printf("dest: %s\n", dest);
	// printf("src: %s\n", src);
	ft_memcpy(dest, src, 3);
	// memcpy(mydest, mysrc, 0);
	// char	*dest = memcpy(((void*)"\0"), ((void*)0), 6);
	printf("new dest: %s\n", dest);
}
*/
