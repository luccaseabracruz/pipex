/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:50:07 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strjoin - Allocates and returns a new string, which is the result of
 * concatenating 's1' and 's2'.
 *
 * @param s1: The prefix string.
 * @param s2: The suffix string.
 *
 * @return: A pointer to the newly allocated string containing the concatenation
 * of 's1' and 's2', or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, (s1_len + s2_len + 1) * sizeof(char));
	ft_strlcat(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	return (ptr);
}

/* int	main(void)
{
	char const	*s1 = "my favorite animal is";
	char const	*s2 = "";
	char const	*s3 = "the nyancat";
	char		*temp = ft_strjoin(s1, s2);
	char		*res = ft_strjoin(temp, s3);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	printf("concatenated: %s\n", res);
	free(res);
	free(temp);
} */