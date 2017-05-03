/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:46:50 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 20:46:51 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

t_tokenlist		*get_token(char *line, t_tokenlist *(*f)(const char *, t_tokenlist *token))
{
	t_tokenlist		*token;
	int 	i;

	token = token_init();
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (line[i] == COMMENT_CHAR)
	{
		token->type = ENDL;
		token->content = line;
	}
	else
		f(line + i, token);
	return (token);
}