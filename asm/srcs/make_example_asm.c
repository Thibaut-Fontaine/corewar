/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_example_asm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:58:08 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:12 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

#define LIVE	1
#define LD		2
#define ST		3
#define ADD 	4
#define SUB 	5
#define AND 	6
#define OR		7
#define XOR 	8
#define ZJMP 	9
#define LDI		10
#define STI 	11
#define FORK 	12
#define LLD 	13
#define LLDI 	14
#define LFORK 	15
#define AFF 	16

static t_header	*make_example_header(void)
{
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(header->prog_name, "Torpille");
	header->prog_size = 138;
	ft_strcpy(header->comment, "by sebc");
	return (header);
}

static t_arglist	*new_arg(char *format)
{
	t_arglist	*new;
	char		**arg;

	arg = ft_strsplit(format, ',');
	new = (t_arglist *)malloc(sizeof(t_arglist));
	new->type = (char)ft_atoi(arg[0]);
	new->value = ft_strdup(arg[1]);
	new->next = NULL;
	return (new);
}

static t_arglist	*push_arg(t_arglist	*head, char *format)
{
	t_arglist	*new;

	if (!head)
		head = new_arg(format);
	else
	{
		new = head;
		while (new->next != NULL)
			new = new->next;
		new->next = new_arg(format);
	}
	return (head);
}

static t_arglist	*make_arglist(char *format)
{
	t_arglist	*arglist;
	char		**args;
	int			i;

	arglist = NULL;
	args = ft_strsplit(format, ';');
	i = 0;
	while (args[i])
	{
		arglist = push_arg(arglist, args[i]);
		i++;
	}
	return (arglist);
}

static t_oplist	*new_op(char type, size_t size, char *format)
{
	t_oplist	*new;

	new = (t_oplist *)malloc(sizeof(t_arglist));
	new->type = type;
	new->size = size;
	new->args = make_arglist(format);
	new->next = NULL;
	return (new);
}

static t_oplist	*push_op(t_oplist *head, char type, size_t size, char *format)
{
	t_oplist	*new;

	if (!head)
		head = new_op(type, size, format);
	else
	{
		new = head;
		while (new->next != NULL)
			new = new->next;
		new->next = new_op(type, size, format);
	}
	return (head);
}

static t_oplist	*make_example_oplist()
{
	t_oplist	*oplist;

	oplist = NULL;
	oplist = push_op(oplist, XOR, 5, "1,4;1,4;1,4");
	// 5
	oplist = push_op(oplist, FORK, 3, "10,debut2");
	oplist = push_op(oplist, ST, 5, "1,1;12,ld1");
	// 13
	oplist = push_op(oplist, LIVE, 5, "2,0");
	oplist = push_op(oplist, ST, 5, "1,1;12,live1");
	oplist = push_op(oplist, LD, 7, "2,-10;1,2");
	oplist = push_op(oplist, LD, 7, "2,1;1,3");
 	// 37
	oplist = push_op(oplist, LIVE, 5, "2,4");
	oplist = push_op(oplist, ADD, 5, "1,2;1,3;1,2");
	oplist = push_op(oplist, ZJMP, 3, "10,live1b");
	oplist = push_op(oplist, XOR, 5, "1,4;1,4;1,4");
	oplist = push_op(oplist, ZJMP, 3, "10,live1");
	// 58
	oplist = push_op(oplist, LD, 7, "2,-10;1,2");
	oplist = push_op(oplist, XOR, 5, "1,4;1,4;1,4");
	oplist = push_op(oplist, ZJMP, 3, "10,live1");
	// 73
	oplist = push_op(oplist, ST, 5, "1,1;12,ld2");
	// 78
	oplist = push_op(oplist, LIVE, 5, "2,0");
	oplist = push_op(oplist, ST, 5, "1,1;12,live2");
	oplist = push_op(oplist, LD, 7, "2,-10;1,2");
	oplist = push_op(oplist, LD, 7, "2,1;1,3");
	// 102
	oplist = push_op(oplist, LIVE, 5, "2,4");
	oplist = push_op(oplist, ADD, 5, "1,2;1,3;1,2");
	oplist = push_op(oplist, ZJMP, 3, "10,live2b");
	oplist = push_op(oplist, XOR, 5, "1,4;1,4;1,4");
	oplist = push_op(oplist, ZJMP, 3, "10,live2");
	// 123
	oplist = push_op(oplist, LD, 7, "2,-10;1,2");
	oplist = push_op(oplist, XOR, 5, "1,4;1,4;1,4");
	oplist = push_op(oplist, ZJMP, 3, "10,live2");
	// 138
	return (oplist);
}

static t_labellist	*push_label(t_labellist *head, char *name, uint32_t pos)
{
	t_labellist	*new;

	new = head;
	while (new->next != NULL)
		new = new->next;
	new->next = (t_labellist *)malloc(sizeof(t_labellist));
	new = new->next;
	new->name = ft_strdup(name);
	new->abs_pos = pos;
	new->next = NULL;
	return (new);
}

static t_labellist	*make_example_labellist(void)
{
	t_labellist	*labels;

	labels = (t_labellist *)malloc(sizeof(t_labellist));
	labels->name = ft_strdup("debut");
	labels->abs_pos = 5;
	labels->next = NULL;

	push_label(labels, "ld1", 13);
	push_label(labels, "live1", 37);
	push_label(labels, "live1b", 58);
	push_label(labels, "debut2", 73);
	push_label(labels, "ld2", 78);
	push_label(labels, "live2", 102);
	push_label(labels, "live2b", 123);
	return (labels);
}

t_asm			*make_example_asm(void)
{
	t_asm	*tasm;

	tasm = (t_asm *)malloc(sizeof(t_asm));
	tasm->header = make_example_header();
	tasm->oplist = make_example_oplist();
	tasm->labellist = make_example_labellist();
	tasm->optab = init_optab();
	return (tasm);
}
