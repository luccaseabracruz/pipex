/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:55:36 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_isalnum - Checks if the given character is alphanumeric.
 * 
 * @param c: The character to check, represented as an integer.
 * 
 * Return: 1 if the character is a letter (a-z, A-Z) or a digit
 * (0-9), 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
	int expected = isalnum(c) != 0; // normalize to 0 or 1
	int result = ft_isalnum(c);

	if (result == expected)
		printf("PASS: ft_isalnum('%c' / %d) == %d\n", c, c, result);
	else
		printf("FAIL: ft_isalnum('%c' / %d) == %d\n"
		       "      (expected %d)\n", c, c, result, expected);
}

int main(void)
{
	int test_cases[] = {
		'0', '5', '9',           // digits
		'A', 'Z', 'a', 'z',      // letters
		'!', '@', '[', '`',      // symbols
		'\n', ' ',               // control and whitespace
		-1, 128, 200,            // out of ASCII range
		48, 57, 65, 90, 97, 122  // ASCII values for '0'-'9', 'A'-'Z', 'a'-'z'
	};

	int count = sizeof(test_cases) / sizeof(test_cases[0]);
	for (int i = 0; i < count; i++)
		run_test(test_cases[i]);

	return 0;
} */