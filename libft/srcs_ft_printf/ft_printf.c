/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:56 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_handle_print(va_list args, const char type);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			format++;
			counter += ft_handle_print(args, *format);
		}
		else
		{
			counter += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (counter);
}

static int	ft_handle_print(va_list args, const char type)
{
	int	counter;

	counter = 0;
	if (type == '%')
		counter += write(1, &type, 1);
	else if (type == 'c')
		counter += ft_print_c(args);
	else if (type == 's')
		counter += ft_print_s(args);
	else if (type == 'p')
		counter += ft_print_p(args);
	else if (type == 'd' || type == 'i')
		counter += ft_print_d(args);
	else if (type == 'u')
		counter += ft_print_u(args);
	else if (type == 'x')
		counter += ft_print_hex(args, "0123456789abcdef");
	else if (type == 'X')
		counter += ft_print_hex(args, "0123456789ABCDEF");
	return (counter);
}
