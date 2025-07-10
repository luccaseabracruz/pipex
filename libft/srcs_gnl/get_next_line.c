/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:08 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/10 11:51:33 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stdlib.h>

/**
 * @function get_next_line
 * @brief Reads the next line from a file descriptor.
 *
 * The `get_next_line` function reads a single line from the given file descriptor
 * (`fd`). It uses a static buffer to store leftover data between calls and reads
 * the file in chunks of size `BUFFER_SIZE`. The function dynamically allocates
 * memory for the returned line, which must be freed by the caller.
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
 * - The function maintains a static buffer to store leftover data between calls.
 * - It reads from the file descriptor in chunks of size `BUFFER_SIZE`.
 * - Stops reading when a newline character (`\n`) is encountered or the end of
 *   the file is reached.
 * - Cleans up the buffer after extracting the line.
 *
 * @note
 * - The function is not thread-safe due to the use of a static buffer.
 * - The caller is responsible for freeing the memory allocated for the returned line.
 *
 * @example
 * #include <fcntl.h>
 * #include <stdio.h>
 * #include "../includes/get_next_line.h"
 *
 * int main(void)
 * {
 *     char *line;
 *     int fd;
 *
 *     fd = open("example.txt", O_RDONLY);
 *     if (fd < 0)
 *         return (1);
 *     while ((line = get_next_line(fd)))
 *     {
 *         printf("%s", line);
 *         free(line);
 *     }
 *     close(fd);
 *     return (0);
 * }
 */

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_bufferlinejoin(NULL, buffer);
	while (!ft_haschr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == '\0')
		{
			free(line);
			ft_cleanbuffer(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_bufferlinejoin(line, buffer);
	}
	ft_cleanbuffer(buffer);
	return (line);
}
