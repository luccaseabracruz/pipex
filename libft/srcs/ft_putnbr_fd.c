/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:56:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putnbr_fd - Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor to write to. 
 * 
 * This function handles negative numbers, including the edge case of INT_MIN,
 * and recursively prints each digit of the number.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + 48, fd);
	}
}

/* int	main(void)
{
	ft_putnbr_fd(123, 1);
	ft_putchar_fd('\n', 1);

	ft_putnbr_fd(-456, 1);
	ft_putchar_fd('\n', 1);

	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);

	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);

	ft_putnbr_fd(INT_MAX, 1);
	ft_putchar_fd('\n', 1);

	return (0);
} */