/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:37:12 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/09 20:27:00 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	write_magic(int fhandle, unsigned int magic)
{
	write(fhandle, &magic, 4);
}

void	write_header(int fhandle, t_header *header)
{
	lseek(fhandle, 0, SEEK_SET);
	write_magic(fhandle, header->magic);
	// write_prog_name(fhandle, header->prog_name);
	// write_prog_size(fhandle, header->prog_size);
	// write_comment(fhandle, header->comment);
}
