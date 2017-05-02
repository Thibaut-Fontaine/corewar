/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/02 02:48:21 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <errno.h>

/*
** open the file, then allocate memory for a buffer to fill it,
** then fill the buffer with it, then close it.
** return the buffer and fill *len with the size of the buffer.
*/

t_file			*open_file(const char *name, int *len)
{
	int				fd;
	unsigned char	*s;
	t_file			*file;

	if ((fd = open(name, O_RDONLY)) == -1)
		error(_ERR_SOURCE_FILE)(name);
	if ((*len = lseek(fd, 0, SEEK_END)) == -1)
		error(_ERR_STDERROR)(name);
	if ((*len = *len - HEADER_LENGTH) <= 0)
		error(_ERR_CH_TOO_SMALL)(name);
	if ((s = malloc(*len)) == NULL)
		error(_ERR_STDERROR)(name);
	//    //    //    //    //
	file = malloc(sizeof(t_file)); // a proteger
	file->prog = malloc(sizeof(*len)); // a proteger
	// parsing a faire ici :
	if (lseek(fd, 0, SEEK_SET) == -1)
		error(_ERR_STDERROR)(name);
	if (read(fd, /*buffer*/, 8)) // mettre dans magic number et tester
		;
	if (read ... // prog_name
			;
	if (read(fd, /*buffer*/, 8)) // mettre dans prog_size et tester
		;
	if (read ..) // comment
		;
	//    //    //    //    //
	file = malloc(sizeof(t_file)); // a proteger
	file->prog = malloc(sizeof(*len)); // a proteger
	//    //    //    //    //
	if (read(fd, s, *len) == -1)
		error(_ERR_STDERROR)(name);
	//
	if (close(fd) == -1)
		error(_ERR_STDERROR)(name);
	return (file);
}
