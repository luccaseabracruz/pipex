/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:16:48 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Checks if a character is part of a given set of characters.
 * 
 * @param c The character to check.
 * @param set The set of characters to compare against.
 * 
 * @return 1 if the character is in the set, 0 otherwise.
 */
static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

/**
 * ft_strtrim - Trims characters from the beginning and end of a string based 
 * 				on a set.
 * 
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim from the string.
 * 
 * @return A new string with the specified characters removed from the start 
 * 		   and end.
 *         Returns an empty string if the input string is empty.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (ft_strlen(s1) == 0)
	{
		return (ft_strdup(""));
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) && start <= end)
	{
		start++;
	}
	while (is_set(s1[end], set) && start <= end)
	{
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}

/* int	main(void)
{
	char const	*s1 = "__UI______";
	char const	*set = "_UI";
	char	*r1 = ft_strtrim(s1, set);
	printf("str: %s\nset: %s\nresponse: %s\n", s1, set, r1);
} */