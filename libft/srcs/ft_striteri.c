/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:03:26 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_striteri - Applies a function to each character of a string, passing the
 *               character's index and a pointer to the character itself.
 * 
 * @param s: The string to iterate over.
 * @param f: The function to apply to each character. It takes the index of the
 *     		 character and a pointer to the character as arguments.
 * 
 * This function allows modifying the string in place by applying the provided
 * function to each character. The function `f` can perform operations such as
 * transforming characters or applying custom logic based on the index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void ft_change_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && ft_isalpha(*c))
		*c = ft_toupper(*c);
}

int	main(void)
{
	char	str[] = "abcdefg";
	printf("before: %s\n", str);
	ft_striteri(str, ft_change_even_index);
	printf("after:  %s\n", str);
} */