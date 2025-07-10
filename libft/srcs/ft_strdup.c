/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:43:40 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strdup - Duplicates a given string.
 * @param s: The string to duplicate.
 *
 * Allocates sufficient memory for a copy of the string `s`, copies the string
 * into the allocated memory, and returns a pointer to it. If memory allocation
 * fails, returns NULL.
 *
 * @return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	s_len;

	s_len = ft_strlen(s);
	cpy = malloc((s_len + 1) * sizeof(char));
	if (!cpy)
	{
		return (NULL);
	}
	ft_strlcpy(cpy, s, s_len + 1);
	return (cpy);
}

/* int	main(void)
{
	char	*original = "Hello, world!";
	char	*copy;

	copy = ft_strdup(original);
	if (copy)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
		free(copy);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
} */