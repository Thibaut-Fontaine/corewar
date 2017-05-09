/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_example_asm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:58:08 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/09 19:43:58 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_header	*make_example_header(void)
{
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(header->prog_name, "A simple program."); // 41 20 73 69 6d 70 6c 65 20 70 72 6f 67 72 61 6d 2e
	header->prog_size = 100;
	ft_strcpy(header->comment, "Test please ignore."); // 54 65 73 74 20 70 6c 65 61 73 65 20 69 67 6e 6f 72 65 2e

	return (header);
}

static t_oplist	*make_example_oplist(void)
{
	t_oplist	*oplist;

	oplist = NULL;
	return (oplist);
}

static t_labellist	*make_example_labellist(void)
{
	t_labellist	*labellist;

	labellist = NULL;
	return (labellist);
}

t_asm	*make_example_asm(void)
{
	t_asm	*tasm;

	tasm = (t_asm *)malloc(sizeof(t_asm));
	tasm->header = make_example_header();
	tasm->oplist = make_example_oplist();
	tasm->labellist = make_example_labellist();
	tasm->optab = init_optab();
	return (tasm);
}
