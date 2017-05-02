/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:37:59 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 20:10:29 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_asm.h"

typedef struct			s_header
{
  unsigned int			magic;
  char					prog_name[PROG_NAME_LENGTH + 1];
  unsigned int			prog_size;
  char					comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct 			s_labellist
{
	char				*name;
	uint32_t			abs_pos;
	struct s_labellist 	*next;
}						t_labellist;

typedef	struct  		s_paramlist
{
	t_arg_type			type;
	void				*value;
	struct s_paramlist	*next;
}						t_paramlist;

typedef	struct 			s_oplist
{
	char				op;
	size_t				size;
	t_paramlist			*params;
	struct s_oplist		*next;
}						t_oplist;

typedef struct 			s_asm
{
	t_header			header;
	t_oplist			*oplist;
	t_labellist			*labels;
} 						t_asm;

#endif
