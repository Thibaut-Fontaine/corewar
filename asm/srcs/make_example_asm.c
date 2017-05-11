/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_example_asm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:58:08 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/11 23:22:13 by mperronc         ###   ########.fr       */
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
	ft_strcpy(header->prog_name, "Olala");
	header->prog_size = 5;
	ft_strcpy(header->comment, "Topkek");

	return (header);
}

static t_oplist	*make_example_oplist(void)
{
	t_oplist	*head;
	t_oplist	*new;

	head = (t_oplist *)malloc(sizeof(t_oplist));
	new = head;

	// OP 1
	new->type = LIVE;
	new->size = 3;
		//ARG 1
	new->args = (t_arglist *)malloc(sizeof (t_arglist));
	new->args->type = T_DIR;
	new->args->value = ft_strdup("%42");
	new->args->next = NULL;

	new->next = (t_oplist *)malloc(sizeof(t_arglist));
	new = new->next;

	// OP 2
	new->type = AND;
	new->size = 9;
		//ARG 1
	new->args = (t_arglist *)malloc(sizeof (t_arglist));
	new->args->type = T_DIR;
	new->args->value = ft_strdup("%42");

	new->args->next = (t_arglist *)malloc(sizeof (t_arglist));
	new->args = new->args->next;
		// ARG 2
	new->args->type = T_IND;
	new->args->value = ft_strdup("77");

	new->args->next = (t_arglist *)malloc(sizeof (t_arglist));
	new->args = new->args->next;
		// ARG 3
	new->args->type = T_REG;
	new->args->value = ft_strdup("r3");
	new->args->next = NULL;

	new->next = NULL;
	return (head);
}

static t_labellist *make_example_labellist(void)
{
	t_labellist	*head;
	t_labellist *new;

	head = (t_labellist *)malloc(sizeof(t_labellist));
	new = head;

	// Label 1
	new->name = ft_strdup("main");
	new->abs_pos = 0;
	new->next = NULL;

	return (head);
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
