/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:20:21 by lseabra-          #+#    #+#             */
/*   Updated: 2025/04/18 11:55:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isprint - Checks if the given character is printable.
 * 
 * @param c: The character to check, represented as an integer.
 * 
 * Return: 1 if the character is printable (including space, 32-126), 
 * 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* #include <stdio.h>
int	main(void)
{
	int test_cases[] = {
		32, 126,                 // printable boundary values
		31, 127,                 // non-printable boundary values
		'A', 'z', '0', '9',      // printable characters
		'\n', '\t', '\r',        // non-printable control characters
		-1, 128, 200             // invalid (outside ASCII range)
	};

	int count = sizeof(test_cases) / sizeof(test_cases[0]);
	for (int i = 0; i < count; i++)
		printf("ft_isprint(%d) = %d\n",
		test_cases[i], ft_isprint(test_cases[i]));

	return 0;
} */