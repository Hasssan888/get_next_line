/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:33:54 by hbakrim           #+#    #+#             */
/*   Updated: 2023/11/28 16:37:54 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_read_and_create(t_list **res, int fd);
void	ft_append(t_list **res, char *buf, int fd);
char	*ft_extract_line(t_list *res);
void	ft_burnish_res(t_list **res);
int		ft_newline_found(t_list *res);
int		ft_len_to_newline(t_list *res);
void	ft_cpystr(t_list *res, char *str);
t_list	*ft_find_last_node(t_list *res);
void	ft_free_res(t_list **res, t_list *clean_node, char *buf);
#endif
