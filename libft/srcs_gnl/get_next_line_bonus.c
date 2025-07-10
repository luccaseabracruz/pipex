/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:31:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 11:50:37 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @function get_next_line
 * @brief Reads the next line from a file descriptor, supporting multiple descriptors.
 *
 * The `get_next_line` function reads a single line from the given file descriptor (`fd`).
 * Unlike the standard implementation in `get_next_line.c`, this version supports multiple
 * file descriptors simultaneously by using an array of static buffers, one for each file
 * descriptor.
 *
 * @param fd The file descriptor to read from. Must be a valid, open file descriptor.
 * @return A pointer to a dynamically allocated string containing the next line,
 *         including the newline character (`\n`) if present. Returns `NULL` if:
 *         - The file descriptor is invalid.
 *         - `BUFFER_SIZE` is less than or equal to 0.
 *         - An error occurs during reading.
 *         - The end of the file is reached and no content is left to return.
 *
 * @details
 * - The function uses a static array of buffers (`buffer[1024]`) to handle multiple
 *   file descriptors simultaneously.
 * - Each file descriptor has its own buffer to store leftover data between calls.
 * - It reads from the file descriptor in chunks of size `BUFFER_SIZE`.
 * - Stops reading when a newline character (`\n`) is encountered or the end of the
 *   file is reached.
 * - Cleans up the buffer after extracting the line.
 *
 * @note
 * - The function is not thread-safe because it uses static buffers. If multiple threads
 *   call the function simultaneously, they may access or modify the same static buffer,
 *   leading to **undefined behavior**, such as data corruption or crashes.
 * - The caller is responsible for freeing the memory allocated for the returned line.
 * - If the file descriptor is closed or no more lines are available, the corresponding
 *   buffer is freed.
 */
char	*get_next_line_bonud(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	line = ft_bufferlinejoin_bonus(NULL, buffer[fd]);
	line = ft_readline(fd, line, buffer[fd]);
	ft_clean_buffer_bonus(buffer[fd]);
	if (!line || !line[0])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
