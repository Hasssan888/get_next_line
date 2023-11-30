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

	//char	*line_2;
	//char	*line_3;

	fd = open("hassan.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	int fd1 = open("bakrim.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd);
		printf("%s", line);
	line = get_next_line(fd1);
		printf("%s", line);
	line = get_next_line(fd1);
		printf("%s", line);
	line = get_next_line(fd1);
		printf("%s", line);
	close(fd);
	return (0);
}
