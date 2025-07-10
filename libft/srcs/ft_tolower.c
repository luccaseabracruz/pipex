/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:07:25 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_tolower - Converts an uppercase letter to its lowercase equivalent.
 * @param c: The character to be converted.
 *
 * If the input character is an uppercase letter (A-Z), it is converted
 * to its corresponding lowercase letter (a-z). If the character is not
 * an uppercase letter, it is returned unchanged.
 *
 * @return: The lowercase equivalent of the character if it is uppercase,
 *         otherwise the character itself.
 */
int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c <= 90)
	{
		c += 32;
	}
	return (c);
}

/* int	main(void)
{
	// Test cases for ft_tolower
	char test1 = 'A';
	char test2 = 'z';
	char test3 = '1';

	printf("Original: %c, ToLower: %c\n",
	 test1, ft_tolower(test1)); // Expected: a
	printf("Original: %c, ToLower: %c\n",
	 test2, ft_tolower(test2)); // Expected: z
	printf("Original: %c, ToLower: %c\n",
	 test3, ft_tolower(test3)); // Expected: 1

	return (0);
} */