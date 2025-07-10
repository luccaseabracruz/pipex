/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:53:15 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strncmp - Compares up to n characters of two strings. 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * 
 * This function compares the strings s1 and s2 up to n characters or until a
 * null-terminator is encountered. It returns the difference between the first
 * differing characters as unsigned char values.
 * 
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or to be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
	{
		return (0);
	}
	i = 1;
	while ((unsigned char)*s1 && (unsigned char)*s2 && i < n)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*int	main(void)
{
	char	*s1 = "BC";
	char	*s2 = "AB";
	size_t	n = 10;

	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
		printf
		(
			"Same behavior\ns1: %s\ns2: %s\norgn res: %d\nmy res: %d\n"
			, s1, s2, strncmp(s1, s2, n), ft_strncmp(s1, s2, n)
		);
	else
		printf
		(
			"Something is wrong\ns1: %s\ns2: %s\norgn res: %d\nmy res: %d\n"
			, s1, s2, strncmp(s1, s2, n), ft_strncmp(s1, s2, n)
		);
}*/