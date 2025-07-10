/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:08:45 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isalpha - Checks if a character is an alphabetic letter.
 * @param c: The character to check, represented as an integer.
 *
 * This function checks whether the given character is an uppercase
 * or lowercase alphabetic letter (A-Z or a-z).
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* #include "../includes/libft.h"
#include <ctype.h>
void run_test(int c)
{
	int expected = isalpha(c) != 0; // convert to 1 or 0
	int result = ft_isalpha(c);

	if (result == expected)
		printf("PASS: ft_isalpha('%c' / %d) == %d\n", c, c, result);
	else
		printf
		(
			"FAIL: ft_isalpha('%c' / %d) == %d (expected %d)\n",
			c,
			c,
			result, 
			expected
		);
}

int main(void)
{
	int test_cases[] = {
		'A', 'Z', 'a', 'z',    // valid letters
		'B', 'y',              // some random letters
		'0', '9',              // digits
		'!', '@', '[', '{',   // special characters
		-1, 128,               // out of ASCII range
		'\n', ' '              // whitespace and control
	};

	int count = sizeof(test_cases) / sizeof(test_cases[0]);
	for (int i = 0; i < count; i++)
		run_test(test_cases[i]);

	return 0;
} */