/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_op_from_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:11:40 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 20:29:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

size_t	generate_op_from_line(char *line, t_oplist *oplist, t_labellist *labels)
{
	size_t		opsize;
	t_tokenlist	*tokens;

	tokens = token_init();


	if get_token(&extract_label, LABEL)
		// on a une label
	get_token(&extract_op, OP)
	while (get_arg_tokens())
		get_sep_token()
	append_endl_token()

	--> token list locale

	calculate_size(tokenlistlocale)
}


get_token(f, type)
	token = malloc(blabla);
	token->content = f(line);
	if token->content
		token->type = type
		return token
	else
		free(token)
		return NULL
