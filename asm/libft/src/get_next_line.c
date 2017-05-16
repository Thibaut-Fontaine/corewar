/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:42:08 by jgagnot           #+#    #+#             */
/*   Updated: 2015/03/30 16:20:52 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"
#include <stdlib.h>
#include <unistd.h>

static	t_stk	*stk_line(int const fd, t_list **ptr)
{
	t_list	*lst;
	t_stk	stk;

	lst = *ptr;
	while (lst)
	{
		if (((t_stk*)(lst->content))->stk_fd == fd)
			return (lst->content);
		lst = lst->next;
	}
	stk.stk_fd = fd;
	stk.stk_str = ft_strnew(BUFF_SIZE);
	if (!stk.stk_str || !(lst = ft_lstnew(&stk, sizeof(t_stk))))
	{
		free(stk.stk_str);
		return (NULL);
	}
	ft_lstadd(ptr, lst);
	return ((*ptr)->content);
}

static int		read_stk(t_stk *stk, char **line)
{
	char	*str2;
	int		ret;

	ret = 0;
	if ((str2 = ft_strchr(stk->stk_str, '\n')))
	{
		*str2 = '\0';
		str2++;
		ret = 1;
	}
	if (!(*line = ft_strdup(stk->stk_str)))
		return (-1);
	if (ret)
		ft_strcpy(stk->stk_str, str2);
	else
		ft_strclr(stk->stk_str);
	return (ret);
}

static int		free_str(char *str, int i)
{
	free(str);
	return (i);
}

static int		readline(char *buf, t_stk *stk, char **line)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		tmp++;
		ft_strcpy(stk->stk_str, tmp);
		ret = 1;
	}
	tmp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	free(tmp);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	t_stk			*stk;
	int				ret;
	char			*buf;

	if (!line || !(BUFF_SIZE > 0) || !(stk = stk_line(fd, &lst)))
		return (-1);
	if (!(ret = read_stk(stk, line)))
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (free_str(buf, -1));
			buf[ret] = '\0';
			if ((ret = readline(buf, stk, line)))
				return (free_str(buf, ret));
		}
		if (**line)
			return (free_str(buf, 1));
		return (free_str(buf, 0));
	}
	return (ret);
}
