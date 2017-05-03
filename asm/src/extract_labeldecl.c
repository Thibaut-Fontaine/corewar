/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_labeldecl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 18:04:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

t_tokenlist		*extract_labeldecl(const char *str, t_tokenlist *token)
{
	int		i;

	i = 0;
	while (str[i] && is_labelchar(str[i]))
			i++;
	if (ft_iswhitespace(str[i]) || ft_isendl(str[i]))
		return (NULL);
	else if (str[i] == LABEL_CHAR)
	{
		token->content = ft_strsub(str, 0, i + 1);
		token->type = LABEL_DECL;
		return (token);
	}
	token->content = ft_strsub(str, 0, i + 1);
	token->type = INVALID;
	return (token);
}
