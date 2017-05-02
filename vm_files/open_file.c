/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/02 02:27:57 by tfontain         ###   ########.fr       */
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
		error(_ERR_SOURCE_FILE)(name);
	if ((*len = lseek(fd, 0, SEEK_END)) == -1)
		error(_ERR_STDERROR)(name);
	if (*len <= HEADER_LENGTH)
		error(_ERR_CH_TOO_SMALL)(name);
	if ((s = malloc(*len)) == NULL)
		error(_ERR_STDERROR)(name);
	if (lseek(fd, 0, SEEK_SET) == -1)
		error(_ERR_STDERROR)(name);
	if (read(fd, s, *len) == -1)
		error(_ERR_STDERROR)(name);
	if (close(fd) == -1)
		error(_ERR_STDERROR)(name);
	return (s);
}
