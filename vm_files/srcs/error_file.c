/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:59:35 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/18 19:28:02 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		bad_source_file(const char *name)
{
	ft_putstr("Can't read source file ");
	ft_putendl(name);
	exit(-1);
}

void		bad_magic_number(const char *name)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" has an invalid header\n");
	exit(-1);
}

void		code_size_differ(const char *name)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" has a code size that differ from what its header says\n");
	exit(-1);
}
