/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:20:57 by rrouille          #+#    #+#             */
/*   Updated: 2023/06/08 16:24:05 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0)
		return (NULL);
	int     i = 0;
	int     rd = 0;
	char    character;
	char    *buffer = malloc(100000);

	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] =  '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return(buffer);
}

int main() {
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
		perror("Failed to open file");
		return 1;
	}

	char *line = NULL;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}

	close(fd);

	return 0;
}
