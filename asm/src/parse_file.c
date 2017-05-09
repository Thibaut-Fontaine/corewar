/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:35:59 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/03 16:36:00 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"


t_asm		*parse_file(char *path)
{
	t_asm 	obj;
	char 	*line;

	asm_init(&obj);
	while (get_next_line(1, &line))
	{
		if (!is_empty(line))
		{
			if (!(obj.header->prog_name && obj.header->comment))
				parse_start(obj.header, line);
	//	else
	//		generate_op_from_line(obj, line);
		}
	}
	return (&obj);
}