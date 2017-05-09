/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:10:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/13 15:10:33 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"

typedef	struct 			s_arglist
{
	char				type;
	int32_t				value;
	struct s_arglist	*prev;
	struct s_arglist	*next;
}						t_arglist;

typedef struct 			s_instruction
{
	char				type;
	t_arglist			args;
}						t_instruction;

typedef struct 			s_asm
{
	unsigned char		*data;
	int 				check_name;
	int 				check_comment;
	t_header 			header;
}						t_asm;

#endif
