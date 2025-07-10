/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:58:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstmap - Iterates through a linked list and applies a function to the 
 * content of each node, creating a new list with the results.
 * @param lst: The address of a pointer to the first node of the list.
 * @param f: The function to apply to the content of each node.
 * @param del: The function to delete the content of a node if needed.
 *
 * @return A new list resulting from the successive applications of 'f'.
 *         Returns NULL if memory allocation fails or if 'lst' is NULL.
 *
 * @note: The 'del' function is used to free the content of a node in case
 *       of an error during memory allocation.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*temp;

	new_lst = NULL;
	while (lst && f && del)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			del(temp);
			break ;
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* void delete_content(void *content)
{
	free(content);
}

t_list *create_test_list(char *arr[], int size)
{
	t_list *head = NULL;
	t_list *new_node;
	for (int i = 0; i < size; i++)
	{
		new_node = ft_lstnew(strdup(arr[i]));
		ft_lstadd_back(&head, new_node);
	}
	return head;
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	char *data[] = {"one", "two", "three"};
	int size = sizeof(data) / sizeof(data[0]);

	t_list *original = create_test_list(data, size);
	t_list *mapped = ft_lstmap(
		original,
		(void *(*)(void *))ft_strdup,
		delete_content
	);

	printf("Original list:\n");
	print_list(original);

	printf("Mapped list:\n");
	print_list(mapped);

	// Free both lists
	ft_lstclear(&original, delete_content);
	ft_lstclear(&mapped, delete_content);

	return 0;
} */