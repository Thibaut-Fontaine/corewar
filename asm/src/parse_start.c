/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:28:39 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 14:28:40 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

int		ft_tablen(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		parse_start(t_header *header, char *line)
{
	char 	**str;

	str = split_spaces(line);
	if (str[0] && extract_command(str[0]) == CMD_NAME)
		header->prog_name = extract_string(str[1]);
	else if (str[0] && extract_command(str[0]) == CMD_COMMENT)
		header->prog_comment = extract_string(str[1]);
	if (str[1] && str[1][0] != COMMENT_CHAR)
}
