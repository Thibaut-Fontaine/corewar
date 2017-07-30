/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/29 06:17:16 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		bad_nflag(void)
{
	ft_putstr("[-n N] argument have to specifie a number between 1 and the ");
	ft_putstr("number of players. All numbers must be differents.\n");
	exit(-1);
}

void		(*error(int err))()
{
	if (err == _ERR_MAGIC_NUMBER)
		return (bad_magic_number);
	if (err == _ERR_SOURCE_FILE)
		return (bad_source_file);
	if (err == _ERR_USAGE)
		return (usage);
	if (err == _ERR_CSIZE_DIFFER)
		return (code_size_differ);
	if (err == _ERR_CH_TOO_SMALL)
		return (champion_too_small);
	if (err == _ERR_STD)
		return (exit_perror);
	if (err == _ERR_CH_TOO_BIG)
		return (champion_too_big);
	if (err == _ERR_TOO_MANY_CH)
		return (too_many_champions);
	if (err == _ERR_BAD_NFLAG)
		return (bad_nflag);
	return (NULL);
}

void		exit_perror(const char *name)
{
	perror(name);
	exit(-1);
}

void		usage(void)
{
	ft_putstr("Usage: ./corewar");
	ft_putstr(" [-d N -s N | -g]");
	ft_putstr(" [[-n N] <champion1.cor> [-n N] <...>]\n");
	exit(-1);
}
