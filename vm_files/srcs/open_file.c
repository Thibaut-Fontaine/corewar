/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 03:43:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/27 16:17:38 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static inline unsigned	swapegal(unsigned int *i)
{
	return (*i = swap_32int(*i));
}

/*
** open the file, then parse all the header in a struct
** and put the exec in memory
** return the struct and close the file.
*/

t_header				*open_file(const char *n, char *prog, t_header *file)
{
	int					fd;
	char				buf[U_];
	int					i;

	(fd = open(n, O_RDONLY)) == -1 ? error(_ERR_SOURCE_FILE)(n) : 0;
	(i = lseek(fd, 0, SEEK_END)) == -1 ? error(_ERR_STD)(n) : 0;
	(i = i - HEADER_LENGTH) <= 0 ? error(_ERR_CH_TOO_SMALL)(n) : 0;
	lseek(fd, 0, SEEK_SET) == -1 ? error(_ERR_STD)(n) : 0;
	read(fd, (void*)&(file->magic), U_) != U_ ? error(_ERR_STD)(n) : 0;
	file->magic = swap_32int(file->magic);
	COREWAR_EXEC_MAGIC != file->magic ? error(_ERR_MAGIC_NUMBER)(n) : 0;
	read(fd, file->prog_name, PRGM + 1) != PRGM + 1 ? error(_ERR_STD)(n) : 0;
	file->prog_name[PROG_NAME_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(n) : 0;
	read(fd, buf, PADDING_PROGN) != PADDING_PROGN ? error(_ERR_STD)(n) : 0;
	read(fd, (void*)&(file->prog_size), U_) != U_ ? error(_ERR_STD)(n) : 0;
	swapegal(&file->prog_size) != (unsigned)i ? error(_ERR_CSIZE_DIFFER)(n) : 0;
	CHMAX < file->prog_size ? error(_ERR_CH_TOO_BIG)(n, file->prog_size) : 0;
	read(fd, file->comment, COM_L + 1) != COM_L + 1 ? error(_ERR_STD)(n) : 0;
	read(fd, buf, PADDING_CMT) != PADDING_CMT ? error(_ERR_STD)(n) : 0;
	file->comment[COMMENT_LENGTH] != '\0' ? error(_ERR_CSIZE_DIFFER)(n) : 0;
	read(fd, prog, i) == -1 ? error(_ERR_STD)(n) : 0;
	close(fd) == -1 ? error(_ERR_STD)(n) : 0;
	return (file);
}
