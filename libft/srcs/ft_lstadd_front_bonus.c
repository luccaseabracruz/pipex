/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:16:47 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstadd_front - Adds a new node at the beginning of the list.
 * @param lst A pointer to the pointer of the first node of the list.
 * @param new The new node to be added to the list.
 * 
 * This function updates the head of the list to point to the new node,
 * and the new node's `next` pointer will point to the previous head.
 * If either `lst` or `new` is NULL, the function does nothing.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* static void	print_int_ll(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%d\n", *((int *)current->content));
		current = current->next;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*new;
	int	n0 = 0;
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	head = ft_lstnew(&n1);
	head->next = ft_lstnew(&n2);
	head->next->next = ft_lstnew(&n3);
	printf("before:\n");
	print_int_ll(head);
	new = ft_lstnew(&n0);
	ft_lstadd_front(&head, new);
	printf("\nafter:\n");
	print_int_ll(head);
} */