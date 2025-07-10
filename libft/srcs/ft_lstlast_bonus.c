/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:26:25 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
	{
		return (NULL);
	}
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

/* int	main(void)
{
	t_list	*head;
	int	n0 = 0;
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	int	n42 = 42;

	head = ft_lstnew(&n0);
	head->next = ft_lstnew(&n1);
	head->next->next = ft_lstnew(&n2);
	head->next->next->next = ft_lstnew(&n3);
	head->next->next->next = ft_lstnew(&n42);
	printf("lst_node_content = %d\n", *(int *)((ft_lstlast(head))->content));
} */