/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 01:56:59 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/22 04:09:37 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list			*ft_generate_l(const int fd)
{
	t_endl		*tmp;
	t_list		*ret;

	if ((tmp = malloc(sizeof(t_endl))) == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->s = malloc(OUTPUT_LEN);
	*(tmp->s) = '\0';
	ret = ft_lstnew(tmp, sizeof(t_endl));
	free(tmp);
	return (ret);
}

t_list			*ft_get_cur(const int fd, t_list *current)
{
	int			f_fd;

	if (current == NULL)
	{
		if (!(current = ft_generate_l(fd)))
			return (NULL);
		return (current->next = current);
	}
	f_fd = ((t_endl*)(current->content))->fd;
	while ((current = current->next))
	{
		if (((t_endl*)(current->content))->fd == fd)
			return (current);
		if (((t_endl*)(current->content))->fd == f_fd)
			break ;
	}
	if (!(current = ft_lstinsert(&current, ft_generate_l(fd), 2)))
		return (NULL);
	return (current);
}

char			*ft_sget(int fd)
{
	static t_list *current = NULL;

	current = ft_get_cur(fd, current);
	return ((((t_endl*)current->content)->s));
}

int				ft_swrite(int fd, const void *buf, size_t count)
{
	char		*tmp;

	tmp = ft_sget(fd);
	while (*tmp)
		++tmp;
	ft_memcpy(tmp, buf, count);
	*(tmp + count) = 0;
	return (count);
}

void			ft_sprint(int fd)
{
	ft_putstr(ft_sget(fd));
}
