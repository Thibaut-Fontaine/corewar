/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:33:30 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/31 00:49:37 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

typedef struct		s_instruct
{
	char			opcode;
	int				*args;
	int				*types;
}					t_instruct;

int					live();
int					ld();
int					st();
int					add();
int					sub();
int					and();
int					or();
int					xor();
int					zjmp();
int					ldi();
int					sti();
int					fork();
int					lld();
int					lldi();
int					lfork();
int					aff();

#endif
