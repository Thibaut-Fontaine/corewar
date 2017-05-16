/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:37:12 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:18 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	write_prog_name(int fhandle, char *prog_name)
{
	int	pad;

	pad = ft_strlen(prog_name);
	ft_putstr_fd(prog_name, fhandle);
	while (pad <= PROG_NAME_LENGTH + 3)
	{
		write(fhandle, "\0", 1);
		pad++;
	}
}

static void	write_comment(int fhandle, char *comment)
{
	int	pad;

	pad = ft_strlen(comment);
	ft_putstr_fd(comment, fhandle);
	while (pad <= COMMENT_LENGTH + 3)
	{
		write(fhandle, "\0", 1);
		pad++;
	}
}

void		write_header(int fhandle, t_asm *tasm)
{
	t_header	*header;

	header = tasm->header;
	lseek(fhandle, 0, SEEK_SET);
	write_number(fhandle, header->magic, 4);
	write_prog_name(fhandle, header->prog_name);
	write_number(fhandle, header->prog_size, 4);
	write_comment(fhandle, header->comment);
}
