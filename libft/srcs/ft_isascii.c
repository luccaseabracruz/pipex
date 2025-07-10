/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:10:24 by lseabra-          #+#    #+#             */
/*   Updated: 2025/04/18 11:54:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isascii - Checks if the given character is part of the ASCII set.
 * 
 * @param c: The character to check, represented as an integer.
 * 
 * Return: 1 if the character is in the ASCII range (0-127), 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* #include <stdio.h>
#include <ctype.h>
void run_test(int c)
{
	int expected = isascii(c) != 0;
	int result = ft_isascii(c);

	if (result == expected)
		printf("PASS: ft_isascii(%d) == %d\n", c, result);
	else
		printf("FAIL: ft_isascii(%d) == %d (expected %d)\n",
		c, result, expected);
}

int main(void)
{
	int test_cases[] = {
		0, 1, 10, 32,            // control and space
		'A', 'z', 127,           // boundary and valid
		-1, 128, 200, 300,       // invalid (outside ASCII)
		48, 57, 65, 90, 97, 122  // ASCII values for '0'-'9', 'A'-'Z', 'a'-'z'
	};

	int count = sizeof(test_cases) / sizeof(test_cases[0]);
	for (int i = 0; i < count; i++)
		run_test(test_cases[i]);

	return 0;
} */