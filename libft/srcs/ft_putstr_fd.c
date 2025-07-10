/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:13:46 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putstr_fd - Outputs a string to the given file descriptor.
 * @param s: The string to output.
 * @param fd: The file descriptor to write to.
 *
 * This function iterates through the string `s` and writes each character
 * to the file descriptor `fd` using the ft_putchar_fd function.
 * If `s` is NULL, the function does nothing.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*int	main(void)
{
	char s = "123";

	ft_putstr_fd(s, 1);
	return (0);
}*/