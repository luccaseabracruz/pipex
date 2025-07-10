/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:29:24 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 10:31:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Allocates memory for an array of nmemb elements of size bytes each and
 * initializes all bytes in the allocated memory to zero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int	main(void)
{
	// Test 1: Allocate memory for an array of integers
	int	*arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		printf("Test 1: Memory allocated for integers.\n");
		for (int i = 0; i < 5; i++)
			printf("arr[%d] = %d\n", i, arr[i]);
		free(arr);
	}
	else
		printf("Test 1: Memory allocation failed.\n");

	// Test 2: Allocate memory for a string
	char	*str = (char *)ft_calloc(6, sizeof(char));
	if (str)
	{
		strcpy(str, "Hello");
		printf("Test 2: String allocated and initialized: %s\n", str);
		free(str);
	}
	else
		printf("Test 2: Memory allocation failed.\n");

	// Test 3: Allocate with zero elements
	void	*zero_alloc = ft_calloc(0, sizeof(int));
	if (zero_alloc)
	{
		printf("Test 3: Zero allocation returned non-NULL pointer.\n");
		free(zero_alloc);
	}
	else
		printf("Test 3: Zero allocation returned NULL pointer.\n");

	// Test 4: Allocate with zero size
	void	*zero_size = ft_calloc(5, 0);
	if (zero_size)
	{
		printf("Test 4: Zero size allocation returned non-NULL pointer.\n");
		free(zero_size);
	}
	else
		printf("Test 4: Zero size allocation returned NULL pointer.\n");

	return (0);
} */