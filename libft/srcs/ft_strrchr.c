/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:18:31 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strrchr - Locates the last occurrence of a character in a string.
 * @param s: The string to be searched.
 * @param c: The character to locate (converted to a char).
 *
 * @return: A pointer to the last occurrence of the character in the string,
 *          or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	const char	*last;

	ptr = s;
	last = s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			last = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		last = ptr;
	if (*last == (char)c)
		return ((char *)last);
	else
		return (NULL);
}

/* int	main(void)
{
	char	*s = "AaBcCDd";
	int		c = 92;
	if (strrchr(s, c) == ft_strrchr(s, c))
		printf("Same behavior.\n");
	else
		printf
		(
			"Something is wrong.\n
			original: %s\n
			My: %s\n"
			, strrchr(s, c), ft_strrchr(s, c)
			);
}*/