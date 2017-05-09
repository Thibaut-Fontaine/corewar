/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bytecode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:12:49 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/09 20:12:43 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	generate_bytecode(t_asm *tasm, char *file)
{
	int		fhandle;

	fhandle = open(file, O_CREAT | O_WRONLY, 0644);
	write_header(fhandle, tasm->header);
	close(fhandle);
}
