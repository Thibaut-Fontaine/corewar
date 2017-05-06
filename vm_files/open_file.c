/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/06 04:09:04 by tfontain         ###   ########.fr       */
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

t_header		*open_file(const char *name, char *prog)
{
	int			fd;
	t_header	*file;
	char		buf[U_];
	int			n;

	(fd = open(name, O_RDONLY)) == -1 ? error(_ERR_SOURCE_FILE)(name) : 0;
	(n = lseek(fd, 0, SEEK_END)) == -1 ? error(_ERR_STD)(name) : 0;
	(n = n - HEADER_LENGTH) <= 0 ? error(_ERR_CH_TOO_SMALL)(name) : 0;
	lseek(fd, 0, SEEK_SET) == -1 ? error(_ERR_STD)(name) : 0;
	(file = malloc(sizeof(t_header))) == NULL ? error(_ERR_STD)(name) : 0;
	read(fd, (void*)&(file->magic), U_) != U_ ? error(_ERR_STD)(name) : 0;
	file->magic = swap_uint(file->magic);
	COREWAR_EXEC_MAGIC != file->magic ? error(_ERR_MAGIC_NUMBER)(name) : 0;
	if (read(fd, file->prog_name, PROG_NAME_LENGTH + 1) != PROG_NAME_LENGTH + 1)
		error(_ERR_STD)(name);
	file->prog_name[PROG_NAME_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	read(fd, buf, PADDING_PROGN) != PADDING_PROGN ? error(_ERR_STD)(name) : 0;
	if (read(fd, (void*)&(file->prog_size), U_) != U_)
		error(_ERR_STD)(name);
	if ((file->prog_size = swap_uint(file->prog_size)) != n)
		error(_ERR_CSIZE_DIFFER)(name);
	CHAMP_MAX_SIZE < file->prog_size ? error(_ERR_CH_TOO_BIG)(name, file->prog_size) : 0;
	if (read(fd, file->comment, COMMENT_LENGTH + 1) != COMMENT_LENGTH + 1)
		error(_ERR_STD)(name);
	read(fd, buf, PADDING_CMT) != PADDING_CMT ? error(_ERR_STD)(name) : 0;
	file->comment[COMMENT_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	read(fd, prog, n) == -1 ? error(_ERR_STD)(name) : 0;
	close(fd) == -1 ? error(_ERR_STD)(name) : 0;
	return (file);
}
