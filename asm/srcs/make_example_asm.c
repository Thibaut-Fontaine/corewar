/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_example_asm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:58:08 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/11 17:50:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_header	*make_example_header(void)
{
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(header->prog_name, "Olala");
	header->prog_size = 5;
	ft_strcpy(header->comment, "Topkek");

	return (header);
}

static t_arglist *add_arg(char *arg)
{
	char		**farg;
	t_arglist	*larg;

	larg = (t_arglist *)malloc(sizeof(t_arglist));
	farg = ft_strsplit(arg, ':');
	if (ft_strcmp(farg[0], "reg") == 0)
		larg->type = 1;
	else if (ft_strcmp(farg[0], "dir") == 0)
		larg->type = 2;
	else if (ft_strcmp(farg[0], "indir") == 0)
		larg->type = 3;
	larg->value = ft_strdup(farg[1]);
	larg->next = NULL;
	free(farg[0]);
	free(farg[1]);
	free(farg);
	return larg;
}

static t_arglist *add_args(char *args)
{
	t_arglist	*list;
	t_arglist	*tmp;
	char 		**arg_tab;
	int			i;

	arg_tab = ft_strsplit(args, ',');
	list = add_arg(arg_tab[0]);
	tmp = list->next;
	i = 1;
	while (arg_tab[i])
	{
		tmp = add_arg(arg_tab[i]);
		tmp = tmp->next;
		i++;
	}
	return (list);
}

static t_oplist *add_op(char code, size_t size, char *args)
{
	t_oplist *op;

	op = (t_oplist *)malloc(sizeof(t_oplist));
	op->type = code;
	op->size = size;
	op->args = add_args(args);
	op->next = NULL;
	return (op);
}

static t_oplist	*make_example_oplist(void)
{
	t_oplist	*oplist;
	t_oplist	*tmp;

	oplist = add_op(1, 5, "reg:1");
	tmp = oplist->next;
	tmp = add_op(4, 5, "reg:1,reg:2,reg:3");
	return (oplist);
}

static t_labellist	*add_label(char *name, uint32_t pos)
{
	t_labellist	*label;

	label = (t_labellist *)malloc(sizeof(t_labellist));
	label->name = ft_strdup(name);
	label->abs_pos = pos;
	label->next = NULL;
	return (label);
}

static t_labellist	*make_example_labellist(void)
{
	t_labellist	*labellist;

	labellist = add_label("main", 0);
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
