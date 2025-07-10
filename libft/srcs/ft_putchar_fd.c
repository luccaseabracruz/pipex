/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:31:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putchar_fd - Outputs the character 'c' to the given file descriptor.
 * 
 * @param c: The character to output.
 * @param fd: The file descriptor to write to. Should be a valid file descriptor.
 * 
 * This function writes the character 'c' to the file descriptor specified
 * by 'fd'. If 'fd' is invalid (less than 0), the function does nothing.
 */
void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
	}
}
/* 
int	main(void)
{
	char c = 'A';

	printf("Output should be: A\nActual output: ");
	ft_putchar_fd(c, 1); // 1 is stdout
	printf("\n");

	return (0);
}
 */
