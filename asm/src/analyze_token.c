/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:41:24 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:41:25 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/asm.h"

void		analyze_token(char *source, t_token *token)
{
	if (!(token->content = extract_string(source)))
	{
		token->type = INVALID;
		return;
	}
	if (token->content[0] == DIRECT_CHAR)
		token->type = ARG_DIR;
	else if (token->content[0] == SEPARATOR_CHAR)
		token->type = ARG_DELIM;
	else if (token->content[0] == COMMAND_CHAR)
		token->type = get_command_type(token->content);
	else if (token->content[0] == STRING_CHAR)
		token->type = STRING;
	else if (token->content[0] == '\n')
		token->type = ENDL;
	else if (token->content[0] == COMMENT_CHAR)
		token->type = COMMENT;
	else
		token->type = get_token_type_from_string(token->content);
}
