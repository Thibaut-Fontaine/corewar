/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:23:58 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:32:02 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct		s_param_parser
{
	int				opcode;
	char			*name;
	int				arg_num;
	int				arg_types[3];
	uint32_t		size;
	uint32_t		label_size;
}					t_param_parser;

typedef struct		s_parser
{
	char			*line;
	int				current_line;
	int				current_char;
	int				check_name;
	int				check_comment;
	int				fd;
	uint32_t		position;
	t_param_parser	*param_parser;
}					t_parser;

#endif
