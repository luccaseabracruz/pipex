/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:50:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * int_size - Calculates the number of characters needed to represent an integer.
 * @param n: The integer to evaluate.
 * 
 * Returns the size of the string required to represent the integer, including
 * the sign if the number is negative.
 */
static size_t	int_size(int n)
{
	size_t	size;

	if (n == INT_MIN)
		return (11);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (++size);
}

/**
 * ft_itoa - Converts an integer to a null-terminated string.
 * @param n: The integer to convert.
 * 
 * Allocates memory and returns a string representation of the integer.
 * Handles special cases like INT_MIN and negative numbers.
 * 
 * Returns:
 * - A pointer to the string representation of the integer.
 * - NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	if (n == INT_MIN)
	{
		return (ft_strdup("-2147483648"));
	}
	size = int_size(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[size] = '\0';
	while (size > (0 + (str[0] == '-')))
	{
		str[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/* 
int	main(void)
{
	int	n = -10;
	printf("n = %d\n", n);
	printf("n = %s\n", ft_itoa(n));
}
 */
