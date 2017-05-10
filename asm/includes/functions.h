/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/13 18:16:32 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char			***init_optab(void);
int				get_operation_type(char *str, t_parser *parser);
void			add_operation(t_oplist **oplist, t_parser *parser, char *str);
void			add_label_to_list(t_labellist **labellist, t_parser *parser,
	char *name);
void			add_argument(t_arglist *current, t_arglist *arglist);
int				is_labelchar(const char c);
void			remove_com(char **line);
void			asm_init(t_asm *obj);
t_param_parser	*param_parser_init(void);
void			ft_error(char *str, t_parser *parser);
t_arglist		*extract_params(t_parser *parser, t_param_parser param_parser,
	t_arglist *arglist);
void			extract_instruction(t_oplist **oplist, t_parser *parser);
void			extract_labeldecl(t_labellist **labellist, t_parser *parser);
void			parse_name(t_asm *obj, t_parser *parser);
void			parse_comment(t_asm *obj, t_parser *parser);
int				parse_header(t_asm *obj, t_parser *parser);
t_asm			parse(char *av);

#endif
