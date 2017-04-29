/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:11:40 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 21:46:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static t_token_type	get_token_type(const char *source)
{
	t_token_type 	type;

	return (type);
}

static void			*get_token_content(const char *source)
{
	void			*content;

	return (content);
}

t_token				*get_next_token(const char *source)
{
	t_token			*token;

	token = (t_token *)malloc(sizeof (t_token));

	// Get token

	return (token);
}
