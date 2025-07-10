/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:49:45 by lseabra-          #+#    #+#             */
/*   Updated: 2025/04/18 11:54:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isdigit - Checks if the given character is a digit (0-9).
 * 
 * @param c: The character to check, represented as an integer.
 * 
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
	int expected = isdigit(c) != 0; // normalize to 0 or 1
	int result = ft_isdigit(c);

	if (result == expected)
		printf("PASS: ft_isdigit('%c' / %d) == %d\n", c, c, result);
	else
		printf("FAIL: ft_isdigit('%c' / %d) == %d\n"
		       "      (expected %d)\n", c, c, result, expected);
}

int main(void)
{
	int test_cases[] = {
		'0', '1', '5', '9',      // valid digits
		'A', 'z',                // letters
		'!', '-', '/', ':',      // just before and after digits
		-5, 127,                 // edge values
		'\n', ' ',               // whitespace / control characters
		48, 57,                  // ASCII values for '0' and '9'
		100, -100                // arbitrary non-digit values
	};

	int count = sizeof(test_cases) / sizeof(test_cases[0]);
	for (int i = 0; i < count; i++)
		run_test(test_cases[i]);

	return 0;
} */