/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/03 20:17:26 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include "./error.h"

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
	ft_putstr("[-d N -s N -v N | -b --stealth | -n --stealth] [-a]");
	ft_putstr("<champion1.cor> <...>\n");
	exit(-1);
}

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

void		champion_too_small(const char *name)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" is too small to be a champion\n");
	exit(-1);
}

void		champion_too_big(const char *name, unsigned int len)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" has too large a code (");
	ft_putnbr(len);
	ft_putstr(" bytes > ");
	ft_putnbr(CHAMP_MAX_SIZE);
	ft_putstr(" bytes)\n");
	exit(-1);
}
