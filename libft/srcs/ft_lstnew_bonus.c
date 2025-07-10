/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:35:14 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstnew - Allocates (with malloc) and initializes a new t_list node.
 * @param content The content to store in the new node.
 * 
 * @return t_list* A pointer to the new node, or NULL if allocation fails.
 * 
 * The `content` parameter is stored as-is in the `content` field of the node.
 * The `next` pointer of the new node is initialized to NULL.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}
/* 
int	main(void)
{
	int		n = 42;
	char	c = 'A';
	char	*s = "Hello!";
	
	t_list	*new_int = ft_lstnew(&n);
	printf("new_int:\n    content = %d\n", *((int *)new_int->content));
	free(new_int);

	t_list	*new_char = ft_lstnew(&c);
	printf("new_char:\n    content = %c\n", *((char *)new_char->content));
	free(new_char);

	t_list	*new_str = ft_lstnew(s);
	printf("new_str:\n    content = %s\n", (char *)new_str->content);
	free(new_str);

	t_list	*new_null = ft_lstnew(NULL);
	printf("new_null:\n    content = %s\n", (char *)new_null->content);
	free(new_str);
}
 */
