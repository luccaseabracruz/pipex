/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:12:56 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/15 20:57:35 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char **argv)
{
	char	*file1;
	char	*file2;

	if (argc >= 5)
	{
		file1 = argv + 1;
		file2 = argv + (argc - 1);
				
	}
	else
	{
		perror("Wrong input");
		return (1);
	}
	return (0);
}