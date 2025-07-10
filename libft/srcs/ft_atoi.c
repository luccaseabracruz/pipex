/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:55:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer.
 *
 * The ft_atoi function parses the initial portion of the string pointed to by
 * nptr, ignoring leading whitespace characters, and converts it to an integer
 * value. It handles optional '+' or '-' signs to determine the sign of the
 * result. The conversion stops when a non-digit character is encountered, and
 * the function returns the integer value converted up to that point.
 *
 * @param nptr Pointer to the null-terminated string to be converted.
 * @return The converted integer value.
 */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}
/* 
int	main(int argc, char ** argv)
{
	int	o;
	int	m;
	if (argc > 1)
	{
		o = atoi(argv[1]);
		m = atoi(argv[1]);
		if (o == m)
			printf("SAME RESULT\n");
		else
			printf("SOMETHING IS WRONG WITH FT_ATOI\n");
		printf("original: %d\n", o);
		printf("my atoi:  %d\n", m);
	}
}
 */
