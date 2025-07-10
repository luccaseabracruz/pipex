/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:33 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strlcpy - Copies up to size - 1 characters from the string src to dst, 
 * null-terminating the result if size is not 0.
 * @param dst  The destination buffer where the string will be copied.
 * @param src  The source string to copy from.
 * @param size The size of the destination buffer.
 * 
 * @return     The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/* 
#include <bsd/string.h>
int	main(void)
{
	char	dst1[] = "";
	char	dst2[] = "";
	char	src[] = "thx to ntoniolo for this test !";
	size_t	r1 = strlcpy(dst1, src, 0);
	size_t	r2 = ft_strlcpy(dst2, src, 0);
	printf("dst1: %s\n r1: %zu\n", dst1, r1);
	printf("dst2: %s\n r2: %zu\n", dst2, r2);

	// char *str = "the cake is a lie !\0I'm hidden lol\r\n";
 	// char buff1[0xF00] = "there is no stars in the sky";
 	// char buff2[0xF00] = "there is no stars in the sky";
 	// size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
 	// size_t r1 = strlcat(buff1, str, max);
 	// size_t r2 = ft_strlcat(buff2, str, max);
	// printf("ds1: %s\n r1: %zu\n", buff1, r1);
	// printf("ds2: %s\n r2: %zu\n", buff2, r2);
 	
 	// char s1[4] = "";
 	// char s2[4] = "";
 	// r1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
 	// r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	// printf("ds1: %s\n r1: %zu\n", s1, r1);
	// printf("ds2: %s\n r2: %zu\n", s2, r2);
}
 */
