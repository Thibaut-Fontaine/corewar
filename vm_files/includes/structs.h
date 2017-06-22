/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:25 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/22 18:49:50 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "op.h"

typedef void		(*t_error)();

typedef struct		s_instruct
{
	int				size;
	char			opcode;
	int				*args;
	int				*types;
}					t_instruct;

typedef struct		s_opt
{
	int				flag;
	int				nd;
	int				ns;
	int				nv;
}					t_opt;

typedef struct		s_champion
{
	int				live;
	char			prog_name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
}					t_champion;

typedef struct		s_process
{
	t_instruct		*instruct;
	int				reg[REG_NUMBER];
	int				pc;
	int				carry;
	int				wait;
	int				id;
}					t_process;

typedef struct		s_argv
{
	t_opt			f;
	int				n_champs;
	t_header		champ[MAX_PLAYERS];
	char			*arena;
	int 			**ref_tab;
}					t_argv;

typedef struct		s_plst
{
	t_process		proc;
	struct s_plst	*nxt;
}					t_plst;

#endif
