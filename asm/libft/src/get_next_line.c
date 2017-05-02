/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 09:11:49 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/15 18:43:00 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int		look_for_endl(char **log, char **line)
{
	char	*endl_ptr;
	char	*updated_log;

	if (*log)
	{
		endl_ptr = ft_strchr(*log, '\n');
		if (endl_ptr)
		{
			*endl_ptr = '\0';
			*line = ft_strdup(*log);
			endl_ptr++;
			if (*endl_ptr != 0)
			{
				updated_log = ft_strdup(endl_ptr);
				ft_strdel(log);
				*log = updated_log;
			}
			else
				ft_strdel(log);
			return (1);
		}
	}
	return (0);
}

static int		read_more(int fd, char **log, int *read_ret)
{
	char	*tmp;
	char	*updated_log;

	tmp = ft_strnew(BUFF_SIZE);
	if ((*read_ret = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	tmp[*read_ret] = '\0';
	if (*log && *read_ret)
	{
		updated_log = ft_strjoin(*log, tmp);
		ft_strdel(&tmp);
		ft_strdel(log);
		*log = updated_log;
	}
	else if (*read_ret)
		*log = tmp;
	else
		ft_strdel(&tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*log[MAX_FD] = {0};
	int				read_ret;
	int				found_endl;

	read_ret = 1;
	found_endl = 0;
	if (fd < 0 || fd > MAX_FD - 1)
		return (-1);
	while (found_endl == 0 && read_ret)
	{
		found_endl = look_for_endl(&log[fd], line);
		if (read_more(fd, &log[fd], &read_ret) == -1)
			return (-1);
	}
	if (found_endl == 1)
		return (1);
	else if (found_endl == 0 && log[fd])
	{
		*line = ft_strdup(log[fd]);
		ft_strdel(&log[fd]);
		return (1);
	}
	return (0);
}
