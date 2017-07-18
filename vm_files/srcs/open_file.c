/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/18 19:45:02 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** open the file, then parse all the header in a struct
** and put the exec in memory
** return the struct and close the file.
*/

static void open_file_(const char **name, t_header **file, int *fd, int *n, char **prog, char (*buf)[U_])
{
	if (read(*fd, (void*)&((*file)->prog_size), U_) != U_)
		error(_ERR_STD)(*name);
	if (((*file)->prog_size = swap_32int((*file)->prog_size)) != (unsigned int)(*n))
		error(_ERR_CSIZE_DIFFER)((*name));
	CHAMP_MAX_SIZE < (*file)->prog_size ? error(_ERR_CH_TOO_BIG)((*name), (*file)->prog_size) : 0;
	if (read(*fd, (*file)->comment, COMMENT_LENGTH + 1) != COMMENT_LENGTH + 1)
		error(_ERR_STD)(*name);
	read(*fd, *buf, PADDING_CMT) != PADDING_CMT ? error(_ERR_STD)(*name) : 0;
	(*file)->comment[COMMENT_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(*name) : 0;
	read(*fd, *prog, *n) == -1 ? error(_ERR_STD)(*name) : 0;
	close(*fd) == -1 ? error(_ERR_STD)(*name) : 0;
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
	file->magic = swap_32int(file->magic);
	COREWAR_EXEC_MAGIC != file->magic ? error(_ERR_MAGIC_NUMBER)(name) : 0;
	if (read(fd, file->prog_name, PROG_NAME_LENGTH + 1) != PROG_NAME_LENGTH + 1)
		error(_ERR_STD)(name);
	file->prog_name[PROG_NAME_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	read(fd, buf, PADDING_PROGN) != PADDING_PROGN ? error(_ERR_STD)(name) : 0;
	open_file_(&name, &file, &fd, &n, &prog, &buf);
	/*	if (read(fd, (void*)&(file->prog_size), U_) != U_)
		error(_ERR_STD)(name);
	if ((file->prog_size = swap_32int(file->prog_size)) != (unsigned int)n)
		error(_ERR_CSIZE_DIFFER)(name);
	CHAMP_MAX_SIZE < file->prog_size ? error(_ERR_CH_TOO_BIG)(name, file->prog_size) : 0;
	if (read(fd, file->comment, COMMENT_LENGTH + 1) != COMMENT_LENGTH + 1)
		error(_ERR_STD)(name);
	read(fd, buf, PADDING_CMT) != PADDING_CMT ? error(_ERR_STD)(name) : 0;
	file->comment[COMMENT_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(name) : 0;
	read(fd, prog, n) == -1 ? error(_ERR_STD)(name) : 0;
	close(fd) == -1 ? error(_ERR_STD)(name) : 0;*/
	return (file);
}
