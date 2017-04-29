/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:02:44 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 16:11:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum 		e_token_type
{
	INVALID,
	ARG_REG,
	ARG_DIR,
	ARG_INDIR,
	ARG_DELIM,
	LABEL_DECL,
	CMD,
	STRING
}					t_token_type;


typedef struct		s_token
{
	t_token_type	type;
	void			*content;
}					t_token;

#endif
