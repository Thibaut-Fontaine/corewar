/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:35:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:13:30 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int						is_labelchar(const char c);
int 					ft_isendl(const char c);
t_tokenlist				*token_init(void);
char					*extract_command(const char *str);
char					*extract_direct(const char *str);
char					*extract_indirect(const char *str);
t_tokenlist				*extract_labeldecl(const char *str, t_tokenlist *token);
char					*extract_op(const char *str);
char					*extract_register(const char *str);
char					*extract_string(const char *str);
t_tokenlist				*get_token(char *line, t_tokenlist *(*f)(const char *, t_tokenlist *token), t_token_type type);

#endif
