/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:32:21 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/29 21:31:24 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*res[1024];
	char			*line_next;

	if (fd < 0 || fd > 1024|| BUFFER_SIZE <= 0 || read(fd, &line_next, 0) < 0)
		return (NULL);
	ft_read_and_create(res, fd);
	if (res[fd] == NULL)
		return (NULL);
	line_next = ft_extract_line(res[fd]);
	ft_burnish_res(&res[fd]);
	return (line_next);
}

void	ft_read_and_create(t_list **res, int fd)
{
	char	*buf;
	int		read_char;

	while (!ft_newline_found(res[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		read_char = read(fd, buf, BUFFER_SIZE);
		if (!read_char)
		{
			free(buf);
			return ;
		}
		buf[read_char] = '\0';
		ft_append(res, buf, fd);
	}
}

void	ft_append(t_list **res, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_find_last_node(res[fd]);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		res[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

char	*ft_extract_line(t_list *res)
{
	char	*str;
	int		len;

	if (res == NULL)
		return (NULL);
	len = ft_len_to_newline(res);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_cpystr(res, str);
	return (str);
}

void	ft_burnish_res(t_list **res)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = ft_find_last_node(*res);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	ft_free_res(res, clean_node, buf);
}

