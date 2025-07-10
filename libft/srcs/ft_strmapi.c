/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:04 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strmapi - Applies a function to each character of a string, creating a 
 * new string.
 * @param s: The input string.
 * @param f: The function to apply to each character, which takes the index 
 * 			 and character as arguments.
 * 
 * @returns: A new string resulting from applying the function to each character
 * 			 of the input string. If memory allocation fails, returns NULL.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*char ft_change_even_index(unsigned int i, char c)
{
	if (i % 2 == 0 && ft_isalpha(c))
		return ft_toupper(c);
	return c;
}

int	main(void)
{
	char	*str = "abcdefg";
	printf("str: %s\n", str);
	printf("res: %s\n", ft_strmapi(str, ft_change_even_index));
} */