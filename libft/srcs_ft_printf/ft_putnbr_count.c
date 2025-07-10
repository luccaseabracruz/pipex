/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:15:58 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:56 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

static size_t	ft_intlen(int nbr);

int	ft_putnbr_count(int nbr)
{
	char	*buffer;
	int		counter;
	size_t	len;

	if (nbr == INT_MIN)
		return (ft_putstr_count("-2147483648"));
	len = ft_intlen(nbr);
	buffer = ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (0);
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr = -nbr;
	}
	while (len > 0 + (buffer[0] == '-'))
	{
		buffer[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	counter = ft_putstr_count(buffer);
	free(buffer);
	return (counter);
}

static size_t	ft_intlen(int nbr)
{
	size_t	counter;

	if (nbr == INT_MIN)
		return (ft_strlen("-2147483648"));
	counter = 1;
	if (nbr < 0)
	{
		counter++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		counter++;
		nbr /= 10;
	}
	return (counter);
}
