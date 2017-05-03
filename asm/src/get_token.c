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
/*
void 			extract_labeldecl(const char *str, t_tokenlist *token)
{
	int		i;
	char	*labeldecl;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (is_labelchar(str[i]))
		{
			token->content = ft_strsub(str, 0, i + 1);
			token->type = INVALID;
			return ;
		}
		else
		{
			return ;
		}
	}
	labeldecl = ft_strsub(str, 0, i + 1);
	return (labeldecl);
}
*/
t_tokenlist		*get_token(char *line, t_tokenlist *(*f)(const char *, t_tokenlist *token), t_token_type type)
{
	t_tokenlist *token;

	token = token_init();
	f(line, token);
	//token->content = f(line);
	//token->next = NULL;
	return (token);
}
