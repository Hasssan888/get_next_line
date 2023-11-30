/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:06 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/29 21:33:18 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_newline_found(t_list *res)
{
	int	i;

	if (res == NULL)
		return (0);
	while (res)
	{
		i = 0;
		while (res->content[i] && i < BUFFER_SIZE)
		{
			if (res->content[i] == '\n')
				return (1);
			++i;
		}
		res = res->next;
	}
	return (0);
}

int	ft_len_to_newline(t_list *res)
{
	int	i;
	int	len;

	if (res == NULL)
		return (0);
	len = 0;
	while (res)
	{
		i = 0;
		while (res->content[i])
		{
			if (res->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		res = res->next;
	}
	return (len);
}

void	ft_cpystr(t_list *res, char *str)
{
	int	i;
	int	j;

	if (res == NULL)
		return ;
	j = 0;
	while (res)
	{
		i = 0;
		while (res->content[i])
		{
			if (res->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = res->content[i++];
		}
		res = res->next;
	}
	str[j] = '\0';
}

t_list	*ft_find_last_node(t_list *res)
{
	if (res == NULL)
		return (NULL);
	while (res->next)
		res = res->next;
	return (res);
}

void	ft_free_res(t_list **res, t_list *clean_node, char *buf)
{
	t_list	*tp;

	if (*res == NULL)
		return ;
	while (*res)
	{
		tp = (*res)->next;
		free((*res)->content);
		free(*res);
		*res = tp;
	}
	*res = NULL;
	if (clean_node->content[0])
		*res = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
