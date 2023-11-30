/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:32 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/29 21:41:29 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_read_and_create(t_list **res, int fd);
void	ft_append(t_list **res, char *buf);
char	*ft_extract_line(t_list *res);
void	ft_burnish_res(t_list **res);
int		ft_newline_found(t_list *res);
int		ft_len_to_newline(t_list *res);
void	ft_cpystr(t_list *res, char *str);
t_list	*ft_find_last_node(t_list *res);
void	ft_free_res(t_list **res, t_list *clean_node, char *buf);
#endif
