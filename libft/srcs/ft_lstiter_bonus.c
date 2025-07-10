/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:39:33 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstiter - Iterates through a linked list and applies a 
 * function to each element's content.
 * @param lst: The beginning of the linked list.
 * @param f: The function to apply to each element's content.
 *
 * This function traverses the linked list starting from the 
 * node pointed to by `lst`. For each node, it applies the function
 * `f` to the `content` of the node. If either `lst` or `f` is NULL, 
 * the function does nothing. The function does not modify the list 
 * itself, only the content of each node.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst && f)
	{
		current = lst;
		while (current)
		{
			f(current->content);
			current = current->next;
		}
	}
}

/* void	to_uppercase(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void	del_function(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *head = ft_lstnew(ft_strdup("hello"));
	head->next = ft_lstnew(ft_strdup("world"));
	head->next->next = ft_lstnew(ft_strdup("libft"));

	printf("Before ft_lstiter:\n");
	print_list(head);

	ft_lstiter(head, to_uppercase);

	printf("\nAfter ft_lstiter:\n");
	print_list(head);

	ft_lstclear(&head, del_function);
	return 0;
} */
