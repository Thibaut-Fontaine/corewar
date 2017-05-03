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

# include "../include/ft_asm.h"

t_tokenlist		*token_init(void)
{
	t_tokenlist 	*token;

	if (!(token = malloc(sizeof(t_tokenlist))))
		ft_putendl_fd("failed to malloc token", -1);
	token->type = INVALID;
	token->content = NULL;
	token->next = NULL;
	return (token);
}
