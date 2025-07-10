/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:55:22 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strnstr - Locates the first occurrence of the null-terminated string
 * 'little' within the string 'big', where not more than 'len' characters
 * are searched. Characters after a '\0' are not searched.
 * @param big: The larger string to search within.
 * @param little: The substring to search for.
 * @param len: The maximum number of characters to search.
 * 
 * @return: A pointer to the beginning of the located substring, or NULL
 * if the substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(little) == 0)
	{
		return ((char *)big);
	}
	while (*big && len > ft_strlen(little) - 1)
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

/* #include <bsd/string.h>
int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *og_ptr;
	char *my_ptr;
	
	og_ptr = strnstr(largestring, smallstring, 4);
	my_ptr = ft_strnstr(largestring, smallstring, 4);
	printf("\n");
	printf("largestring = %s\n", largestring);
	printf("smallstring = %s\n", smallstring);
	if (og_ptr == my_ptr)
		printf("Same result\n");
	else
		printf("Something wrong with ft_strnstr\n");
	printf("og_ptr = %s\n", og_ptr);
	printf("my_ptr = %s\n", my_ptr);
}*/