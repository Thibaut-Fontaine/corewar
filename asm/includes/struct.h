/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:51:44 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/10 06:38:48 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "op.h"
# include <stdlib.h>

typedef struct 			s_labellist
{
	char				*name;
	uint32_t			abs_pos;
	struct s_labellist 	*next;
}						t_labellist;

typedef	struct 			s_arglist
{
	char				type;			// 1 for reg, 2 for dir , 3 for indir
	char				*value;
	struct s_arglist	*next;
}						t_arglist;

typedef struct 			s_oplist
{
	char				type;			//just opcode
	size_t				size;
	t_arglist			*args;
	struct s_oplist		*next;
}						t_oplist;

typedef struct 			s_asm
{
	t_labellist			*labellist;
	t_oplist			*oplist;
	t_header 			*header;
	char				***optab;
}						t_asm;

#endif
