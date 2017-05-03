/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/03 20:32:26 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <errno.h>

/*
** open the file, then parse all the header in a struct
** and put the exec in memory
** return the struct and close the file.
*/

static uint		swap_uint(unsigned int n)
{
	return (((n >> 24) & 0xff) | ((n << 8) & 0xff0000) |
			((n >> 8) & 0xff00) | ((n << 24) & 0xff000000));
}

t_file			*open_file(const char *name, int *n)
{
	int				fd;
	t_file			*file;
	char			buf[U_];

	(fd = open(name, O_RDONLY)) == -1 ? error(_ERR_SOURCE_FILE)(name) : 0;
	(*n = lseek(fd, 0, SEEK_END)) == -1 ? error(_ERR_STD)(name) : 0;
	(*n = *n - HEADER_LENGTH) <= 0 ? error(_ERR_CH_TOO_SMALL)(name) : 0;
	lseek(fd, 0, SEEK_SET) == -1 ? error(_ERR_STD)(name) : 0;
	(file = malloc(sizeof(t_file))) == NULL ? error(_ERR_STD)(name) : 0;
	read(fd, (void*)&(file->info.magic), U_) != U_ ? error(_ERR_STD)(name) : 0;
	file->info.magic = swap_uint(file->info.magic);
	COREWAR_EXEC_MAGIC != file->info.magic ? error(_ERR_MAGIC_NUMBER)(name) : 0;
	if (read(fd, file->info.prog_name, PROG_NAME_LENGTH + 1) != PROG_NAME_LENGTH + 1)
		error(_ERR_STD)(name);
	file->info.prog_name[PROG_NAME_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	read(fd, buf, PADDING_PROGN) != PADDING_PROGN ? error(_ERR_STD)(name) : 0;
	if (read(fd, (void*)&(file->info.prog_size), U_) != U_)
		error(_ERR_STD)(name);
	if ((file->info.prog_size = swap_uint(file->info.prog_size)) != *n)
		error(_ERR_CSIZE_DIFFER)(name);
	CHAMP_MAX_SIZE < file->info.prog_size ? error(_ERR_CH_TOO_BIG)(name, file->info.prog_size) : 0;
	if (read(fd, file->info.comment, COMMENT_LENGTH + 1) != COMMENT_LENGTH + 1)
		error(_ERR_STD)(name);
	read(fd, buf, PADDING_CMT) != PADDING_CMT ? error(_ERR_STD)(name) : 0;
	file->info.comment[COMMENT_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	(file->prog = malloc(sizeof(*n))) == NULL ? error(_ERR_STD)(name) : 0;
	read(fd, file->prog, *n) == -1 ? error(_ERR_STD)(name) : 0;
	close(fd) == -1 ? error(_ERR_STD)(name) : 0;
	return (file);
}
