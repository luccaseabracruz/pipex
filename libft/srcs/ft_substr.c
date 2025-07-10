/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:26:32 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_substr - Allocates and returns a substring from the string 's'.
 * @param s: The source string.
 * @param start: The start index of the substring in the string 's'.
 * @param len: The maximum length of the substring.
 *
 * @returns: A pointer to the substring, or NULL if the allocation fails. 
 * If 'start' is greater than the length of 's', an empty string is returned.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		return (ft_strdup(""));
	}
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

/* int	main(void)
{
	char const		*s = "Itanhaem";
	unsigned int	start = 7;
	size_t			size = 2;
	char	*r1 = ft_substr(s, start, size);
	printf("str: %s\n", s);
	printf("return:%s\n", r1);
} */