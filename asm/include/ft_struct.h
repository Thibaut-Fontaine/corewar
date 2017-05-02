/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:37:59 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/28 18:10:10 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_asm.h"

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

typedef	struct 			s_linelist
{
	char				op;
	size_t				size;
	t_paramlist			*params;
	struct s_linelist	*next;
}						t_linelist;

typedef struct 			s_object
{
	t_linelist			*lines;
	t_labellist			*labels;
	t_header			header;
} 						t_object;

#endif
