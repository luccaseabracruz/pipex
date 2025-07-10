/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:21:25 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:56 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_ptrlen_base(uintptr_t nbr);

int	ft_print_p(va_list args)
{
	uintptr_t	arg;
	size_t		len;
	char		*buffer;
	int			res;

	arg = (uintptr_t)va_arg(args, void *);
	if (!arg)
		return (ft_putstr_count("(nil)"));
	len = ft_ptrlen_base(arg) + 2;
	buffer = ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (0);
	ft_strlcpy(buffer, "0x", 3);
	while (len > 2)
	{
		buffer[--len] = "0123456789abcdef"[arg % 16];
		arg /= 16;
	}
	res = ft_putstr_count((const char *)buffer);
	free(buffer);
	return (res);
}

static size_t	ft_ptrlen_base(uintptr_t nbr)
{
	char	*base;
	size_t	base_len;
	size_t	len;

	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	len = 1;
	while (nbr >= base_len)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}
