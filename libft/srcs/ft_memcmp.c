/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:29:04 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memcmp - Compares the first n bytes of the memory areas s1 and s2.
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * 
 * @return Returns 0 if all bytes are equal or n is equal to 0. If a difference
 *         is found, returns a positive or negative value depending on whether
 *         the first differing byte in s1 is greater or less than the one in s2.
 *         The comparison is done using unsigned characters.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (n == 0)
	{
		return (0);
	}
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n > 1 && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		n--;
	}
	return (*ps1 - *ps2);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcdez";
	size_t n = 5;

	printf("ft_memcmp result: %d\n", ft_memcmp(str1, str2, n));
	printf("memcmp result: %d\n", memcmp(str1, str2, n));

	n = 6;
	printf("ft_memcmp result: %d\n", ft_memcmp(str1, str2, n));
	printf("memcmp result: %d\n", memcmp(str1, str2, n));

	return (0);
} */