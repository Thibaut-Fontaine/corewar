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

int				is_labelchar(const char c);
void			remove_com(char **line);
void			asm_init(t_asm *obj);
void			ft_error(char *str, t_parser *parser);
void			extract_labeldecl(t_labellist *labellist, t_parser *parser, uint32_t position);
void			parse_name(t_asm *obj, t_parser *parser);
void			parse_comment(t_asm *obj, t_parser *parser);
int				parse_header(t_asm *obj, t_parser *parser);
t_asm			parse(char *av);

#endif
