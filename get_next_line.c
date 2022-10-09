/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:33 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:30:33 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*temp;
	char		*line;
	int			i;
	int			readn;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	readn = 1;
	i = -1;
	line = 0;
	while (readn && i < 0)
	{
		if (buf[fd][0] == 0)
			readn = read(fd, buf[fd], BUFFER_SIZE);
		i = nl_index(buf[fd]);
		if (readn > 0)
		{
			temp = line;
			line = get_line(temp, buf[fd]);
		}
		clean_buf(buf[fd]);
	}
	return (line);
}

// int main()
// {
// 	int fd = open("./test.txt", 0);

// 	char *str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		printf("--NEWLINE--\n");
// 	}
// 	close(fd);
// }
