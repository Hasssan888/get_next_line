/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:38:37 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/29 15:38:40 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*line_1;
	char	*line_2;
	char	*line_3;

	fd = open("hassan.txt", O_RDONLY);
	int fd1 = open("bakrim.txt", O_RDONLY);
	int fd2 = open("file3.txt", O_RDONLY);
	int fd3 = open("file4.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line_1 = get_next_line(fd1);
		printf("%s", line_1);
		line_2 = get_next_line(fd2);
		printf("%s", line_2);
		line_3 = get_next_line(fd3);
		printf("%s", line_3);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}
