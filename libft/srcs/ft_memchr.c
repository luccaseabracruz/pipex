/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:02:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memchr - Locates the first occurrence of a character in a memory block.
 * @param s: Pointer to the memory block to search.
 * @param c: Character to locate (converted to unsigned char).
 * @param n: Number of bytes to search.
 *
 * @return A pointer to the first occurrence of the character in the memory
 * block, or NULL if the character is not found within the first n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char	str[] = "Hello, world!";
	char		ch = 'o';
	char		*result;

	result = ft_memchr(str, ch, sizeof(str));
	if (result)
		printf("Character '%c' found at position: %ld\n", ch, result - str);
	else
		printf("Character '%c' not found.\n", ch);
	return (0);
} */