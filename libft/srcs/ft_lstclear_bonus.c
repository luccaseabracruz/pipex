/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:23:44 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstclear - Frees the memory of a linked list and its contents.
 * @param lst A double pointer to the first node of the list.
 * @param del A function pointer to free the content of each node.
 * 
 * This function iterates through a linked list, applying the provided
 * `del` function to free the content of each node, and then frees the
 * node itself. The pointer to the list is set to NULL after clearing.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*save_next;

	if (lst && *lst && del)
	{
		current = *lst;
		while (current)
		{
			save_next = current->next;
			del(current->content);
			free(current);
			current = save_next;
		}
		*lst = NULL;
	}
}

/* void	del_function(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *head = ft_lstnew(ft_strdup("Node 1"));
	head->next = ft_lstnew(ft_strdup("Node 2"));
	head->next->next = ft_lstnew(ft_strdup("Node 3"));

	printf("Before clear: %s\n", (char *)head->content);

	ft_lstclear(&head, del_function);

	if (!head)
		printf("List successfully cleared.\n");
	else
		printf("List not cleared properly.\n");

	return 0;
} */
