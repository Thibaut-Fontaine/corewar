/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:19:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 18:18:50 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

int				is_valid_op(const char *str)
{
	char 	*tab[16] = {"lfork","sti", "fork", "lld", "ld", "add", "zjmp", "sub", "ldi", "or", "st", "aff", "live", "xor", "lldi"};
	int 	i;

	i = 0;
	while (tab[i])
	{
		if (!(ft_strcmp(tab[i], str)))
			return (1);
		i++;
	}
	return (0);
}

t_tokenlist		*extract_op(const char *str, t_tokenlist *token)
{
	int		i;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
	{
		if (!is_labelchar(str[i]))
		{
			token->type = INVALID;
			token->content = ft_strsub(str, 0, i);
			return (token);
		}
		i++;
	}
	token->content = ft_strsub(str, 0, i);
	if (is_valid_op(token->content))
		token->type = OP;
	return (token);
}
