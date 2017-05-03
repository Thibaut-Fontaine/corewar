/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/03 17:15:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <errno.h>

/*
** open the file, then allocate memory for a buffer to fill it,
** then fill the buffer with it, then close it.
** return the buffer and fill *len with the size of the buffer.
*/

static uint		swap_uint(unsigned int n)
{
	return (((n >> 24) & 0xff) | ((n << 8) & 0xff0000) |
			((n >> 8) & 0xff00) | ((n << 24) & 0xff000000));
}

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
	if (lseek(fd, 0, SEEK_SET) == -1)
		error(_ERR_STDERROR)(name);
	if ((file = malloc(sizeof(t_file))) == NULL)
		error(_ERR_STDERROR)(name);
	if (read(fd, (void*)&(file->info.magic), UINT_LEN) != UINT_LEN)
		error(_ERR_STDERROR)(name);
	file->info.magic = swap_uint(file->info.magic);
	COREWAR_EXEC_MAGIC != file->info.magic ? error(_ERR_MAGIC_NUMBER)(name) : 0;
	if (read(fd, file->info.prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error(_ERR_STDERROR)(name);
	file->info.prog_name[PROG_NAME_LENGTH] = 0;
	if (read(fd, (void*)&(file->info.prog_size), UINT_LEN) != UINT_LEN)
		error(_ERR_STDERROR)(name);
	file->info.prog_size = swap_uint(file->info.prog_size);
	CHAMP_MAX_SIZE < file->info.prog_size ? error(_ERR_CH_TOO_BIG)(name) : 0;
	if (read(fd, file->info.comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error(_ERR_STDERROR)(name);
	file->info.comment[COMMENT_LENGTH] = 0;
	if ((file->prog = malloc(sizeof(*len))) == NULL)
		error(_ERR_STDERROR)(name);
	if (read(fd, file->prog, *len) == -1)
		error(_ERR_STDERROR)(name);
	if (close(fd) == -1)
		error(_ERR_STDERROR)(name);
	return (file);
}
