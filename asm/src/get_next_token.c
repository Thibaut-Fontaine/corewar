/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:11:40 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 16:21:39 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static t_token_type	get_token_type(char *str)
{
	t_token_type	type;

	return (type);
}

static void	*get_token_content(t_token_type type, char *str)
{
	void	*content;

	return (content);
}

t_token		*get_next_token(char **pstr)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof (t_token));
	token->type = get_token_type(*pstr);
	token->content = get_token_content(token->type, *pstr);
	update_pstr(token, pstr);
	return (token);
}
