/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type_from_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:42:20 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:42:21 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/asm.h"

static int 	is_op_token(const char *source)
{
	
}

static int 		is_indir_token(const char *source)
{
	int 	i;

	if (i = ft_atoi(source) != 0)
		return (1);
	i = 1;
	if (source[0] != LABEL_CHAR)
		return (0);
	while (source[i])
	{
		if (!(ft_strchr(LABEL_CHARS, source[i])))
			return (0);
	}
	return (1);
}

static int 	is_reg_token(const char *source)
{
	int 	i;
	
	i = 1;
	if (source[0] != 'n')
		return (0);
	while (source[i])
	{
		if (!(ft_isdigit(source[i])))
			return (0);
		i++;
	}
	return (1);
}

static int 	is_label_token(const char *source)
{
	int 	i;

	i = 0;
	while (i < ft_strlen(source))
	{
		if (!(ft_strchr(LABEL_CHARS, source[i])))
			return (0);
		i++;
	}
	if (source[i] == LABEL_CHAR)
		return (1);
	return (0);
}

int 		get_token_type_from_string(const char *source)
{
	if (is_label_token(source))
		return (LABEL);
	else if (is_reg_token(source))
		return (REG);
	else if (is_indir_token(source))
		return (INDIR);
	else if (is_op_token(source))
		return (OP);
	return(INVALID);
}