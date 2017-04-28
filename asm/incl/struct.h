/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:37:59 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/28 15:38:00 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct 		s_labellist
{
	char			*name;
	uint32			abs_pos;
	t_labellist 	*next;
}					t_labellist;;

typedef	struct  	s_paramlist
{
	t_arg_type		type;			
	void			*value;
	t_paramlist		*next;

}					t_paramlist;

typedef	struct 		s_linelist
{
	char			op;
	size_t			size;
	t_paramlist		*params;
	t_linelist		*next;
}					t_linelist;

typedef struct 		s_object
{
	t_linelist		*lines;
	t_labellist		*labels;
	t_header		header;
} 					t_object;

#endif
