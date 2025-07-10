/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:07:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

/**
 * This file contains the implementation of the ft_memmove function, which
 * copies memory from one location to another while handling overlapping
 * memory areas. It uses a helper function, ft_backwards_memcpy, to copy
 * memory safely when the source and destination overlap.
 * 
 * ft_memmove - Copies memory from one location to another, handling overlap.
 * @param dst: Pointer to the destination memory block.
 * @param src: Pointer to the source memory block.
 * @param n: The number of bytes to copy.
 *
 * @return A pointer to the destination memory block.
 * This function is safe to use when memory areas overlap.
 */
static void	*ft_backwards_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cp;
	char	*src_cp;

	dest_cp = (char *)dest;
	src_cp = (char *)src;
	if (dest_cp == NULL && src_cp == NULL)
	{
		return (NULL);
	}
	while (n > 0)
	{
		n--;
		dest_cp[n] = src_cp[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
	{
		return (dest);
	}
	if (src < dest && src + n >= dest)
	{
		ft_backwards_memcpy(dest, src, n);
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/* int main(void)
{
	char src1[] = "Hello, World!";
	char dest1[20];
	char src2[] = "Overlap Test";
	char dest2[20];

	// Test 1: Non-overlapping memory
	ft_memmove(dest1, src1, strlen(src1) + 1);
	printf("Test 1 - Non-overlapping: %s\n", dest1);

	// Test 2: Overlapping memory (src < dest)
	strcpy(dest2, src2);
	ft_memmove(dest2 + 3, dest2, strlen(dest2) + 1);
	printf("Test 2 - Overlapping (src < dest): %s\n", dest2);

	// Test 3: Overlapping memory (dest < src)
	strcpy(dest2, src2);
	ft_memmove(dest2, dest2 + 3, strlen(dest2 + 3) + 1);
	printf("Test 3 - Overlapping (dest < src): %s\n", dest2);

	return 0;
} */