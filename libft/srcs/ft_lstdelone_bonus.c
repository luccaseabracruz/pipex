/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:59:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstdelone - Deletes a single node of a linked list. 
 * @param lst Pointer to the node to be deleted.
 * @param del Function pointer to a function that frees the content of the node.
 * 
 * This function takes a pointer to a node and a function pointer `del` 
 * that is used to free the content of the node. It first applies the 
 * `del` function to the content of the node and then frees the node itself.
 * 
 * @note The `lst` pointer must not be NULL, and the `del` function must be 
 *       provided to avoid undefined behavior.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/* void	del_content(void *content)
{
	if (content)
	{
		printf("Deleting content: %s\n", (char *)content);
		free(content);
	}
}

int	main(void)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	char *str = strdup("Olá, mundo!");
	if (!str)
	{
		free(node);
		return (1);
	}
	node->content = str;
	node->next = NULL;
	ft_lstdelone(node, del_content);
	if (!node)
		printf("Node delected\n");
	else
		printf("Node was not delected\n");
	return (0);
} */