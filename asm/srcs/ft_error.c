/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:44:29 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/24 13:55:10 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	print_token(t_parser *parser)
{
	int		i;

	i = 0;
	while (parser->line[parser->current_char + i] &&
		!ft_iswhitespace(parser->line[parser->current_char + i]))
	{
		ft_putchar_fd(parser->line[parser->current_char + i], 2);
		i++;
	}
}

void		param_error(t_arglist *arg, int type, t_asm *obj, t_parser *parser)
{
	char	*prefix;

	if (arg->type == T_REG)
		prefix = "r";
	else if (arg->type == T_DIR)
		prefix = "%";
	else if (arg->type == T_DIR + T_LAB)
		prefix = "%:";
	else
		prefix = ":";
	ft_putstr_fd("Invalid parameter: ", 2);
	ft_putstr_fd(prefix, 2);
	ft_putstr_fd(arg->value, 2);
	ft_putstr_fd(", expected argument of type ", 2);
	expected_type(type);
	ft_putstr_fd(" at line ", 2);
	ft_putnbr_fd(arg->line, 2);
	write(2, "\n", 1);
	free_asm(obj);
	free_parser(parser);
	exit(-1);
}

void		label_error(char *str, int i, t_asm *obj, t_parser *parser)
{
	ft_putstr_fd("No such label ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" while attempting to dereference token at line : ", 2);
	ft_putnbr_fd(i, 2);
	write(2, "\n", 1);
	free_asm(obj);
	free_parser(parser);
	exit(-1);
}

void		format_error(char *str, t_asm *obj, t_parser *parser)
{
	ft_putstr_fd("Syntax error at line ", 2);
	ft_putnbr_fd(parser->current_line, 2);
	ft_putstr_fd(" : Invalid token : [", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("]", 2);
	free_asm(obj);
	free_parser(parser);
	exit(-1);
}

void		ft_error(char *str, t_parser *parser, t_asm *obj)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putnbr_fd(parser->current_line, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd("Invalid token :[", 2);
	print_token(parser);
	ft_putendl_fd("]", 2);
	free_asm(obj);
	free_parser(parser);
	exit(-1);
}
