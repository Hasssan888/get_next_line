/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:50:09 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/29 21:29:45 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*res;
	char			*line_next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_next, 0) < 0)
		return (NULL);
	ft_read_and_create(&res, fd);
	if (res == NULL)
		return (NULL);
	line_next = ft_extract_line(res);
	ft_burnish_res(&res);
	return (line_next);
}

void	ft_read_and_create(t_list **res, int fd)
{
	char	*buf;
	int		read_char;

	while (!ft_newline_found(*res))
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
		ft_append(res, buf);
	}
}

void	ft_append(t_list **res, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_find_last_node(*res);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*res = new_node;
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
