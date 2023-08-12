/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:20:57 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/12 16:18:20 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(100000);
	rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	line = NULL;
	line = get_next_line(fd);
	while (!line)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
