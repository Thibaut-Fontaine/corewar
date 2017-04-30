/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/30 22:59:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <errno.h>

/*
** open the file, then allocate memory for a buffer to fill it,
** then fill the buffer with it, then close it.
** return the buffer and fill *len with the size of the buffer.
*/

unsigned char		*open_file(const char *name, int *len)
{
	int				fd;
	unsigned char	*s;

	if ((fd = open(name, O_RDONLY)) == -1)
		bad_source_file(name);
	if ((*len = lseek(fd, 0, SEEK_END)) == -1)
		exit(-1);
	if ((s = malloc(*len)) == NULL)
		exit(-1);
	if (lseek(fd, 0, SEEK_SET) == -1)
		exit(-1);
	if (read(fd, s, *len) == -1)
		exit(-1);
	if (close(fd) == -1)
		close_error(name);
	return (s);
}
