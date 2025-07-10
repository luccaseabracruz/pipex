/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:30:32 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/09 19:33:52 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(va_list args);
int		ft_print_s(va_list args);
int		ft_print_p(va_list args);
int		ft_print_d(va_list args);
int		ft_print_u(va_list args);
int		ft_print_hex(va_list args, char *base);

int		ft_putchar_count(int c);
int		ft_putstr_count(const char *s);
int		ft_putnbr_count(int nbr);
int		ft_putunbr_count(unsigned int nbr);
size_t	ft_uintlen_base(unsigned int nbr, char *base);

#endif