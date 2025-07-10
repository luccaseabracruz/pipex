/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:54:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_toupper - Converts a lowercase alphabetic character to its uppercase 
 * equivalent. If the character is not a lowercase alphabetic character, it 
 * is returned unchanged.
 * @param c The character to be converted.
 * 
 * @return: The uppercase equivalent if c is a lowercase letter, otherwise c.
 */
int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 97)
	{
		c -= 32;
	}
	return (c);
}

/* int	main(void)
{
	// Test cases for ft_toupper
	char test_chars[] = {'a', 'z', 'A', 'Z', '1', '!', '\n'};
	int i;

	for (i = 0; i < 7; i++)
	{
		char c = test_chars[i];
		printf("Original: %c, Uppercase: %c\n", c, ft_toupper(c));
	}
	return (0);
} */