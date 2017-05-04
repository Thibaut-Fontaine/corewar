/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:02:44 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 20:09:13 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TOKEN_BUFFSIZE	2048

typedef enum 			e_token_type
{
	INVALID,
	ARG_REG,			// r[0-9+]
	ARG_DIR,			// [DIRECT_CHAR[-][0-9+] OU [DIRECT_CHAR][LABEL_CHAR][labelcharset+]
	ARG_INDIR,			// [-][0-9+] OU LABEL_CHAR[labelcharset+]
	ARG_DELIM,			// SEPARATOR_CHAR
	LABEL_DECL,			// [labelcharset+]LABEL_CHAR
	CMD_NAME,			// [COMMAND_CHAR][a-z+]
	CMD_COMMENT			// [COMMAND_CHAR][a-z+]
	STRING,				// [STRING_CHAR][ascii+][STRING_CHAR]
	OP,					// [a-z+][space]
	ENDL,				// \n
	COMMENT				// COMMENT_CHAR
}						t_token_type;

typedef struct			s_tokenlist
{
	t_token_type		type;
	char				*content;
	int					padding;
	struct s_tokenlist 	*next;
}						t_tokenlist;
#endif
