/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:11:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strchr - Locates the first occurrence of a character in a string.
 * @param s: The string to search.
 * @param c: The character to locate (converted to unsigned char).
 *
 * @return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if (*ptr == (char)c)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (*ptr == (char)c)
	{
		return ((char *)ptr);
	}
	return (NULL);
}

/* int	main(void)
{
	char 	*s = "I'm Stephanie";
	int	c = -204;
	char	*r1 = strchr(s, c);
	char	*r2 = ft_strchr(s, c);
	if (r1 == r2)
		printf("same result\n");
	else
		printf("something is wrong\n");
} */