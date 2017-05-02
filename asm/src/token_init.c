/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:53:33 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 20:53:34 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/asm.h"

t_tokenlist		*token_init(void)
{
	t_tokenlist 	*token;

	if (!(token = malloc(sizeof(t_tokenlist))))
		ft_error("failed to malloc token", -1);
	token->type = INVALID;
	token->content = NULL;
	token->next = NULL;
	return (token);
}
