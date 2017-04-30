/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/30 03:46:07 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>
*/

int					ret_flag(char c)
{
	if (c == 'a')
		return (0);
	else if (c == 'd')
		return (_d_);
	else if (c == 's')
		return (_s_);
	else if (c == 'v')
		return (_v_);
	else if (c == 'b')
		return (_b_);
	else if (c == 'n')
		return (_n_);
	else
		return (0);
}

int					fill_flag(t_opt *f, const char *c)
{
	if (c[0] == '-')
	{
		if (c[2] == 0)
		{
			f->flag |= ret_flag(c[1]);
			return (ret_flag(c[1]));
		}
	}
	return (0);
}

void				get_arg(int i, t_opt *f, const char *argv[])
{
	if (i == _d_)
		f->nd = ft_atoi(*argv);
	else if (i == _s_)
		f->ns = ft_atoi(*argv);
	else if (i == _v_)
		f->nv = ft_atoi(*argv);
	else if ((i == _b_ || i == _n_) && ft_strequ(*argv, "--stealth"))
		f->flag |= _stealth_;
}

t_opt				*get_option(int argc, const char *argv[])
{
	static t_opt	f;
	int		tmp;

	ft_bzero(&f, sizeof(f));
	while (argc)
	{
		if (argc >= 2 && (tmp = fill_flag(&f, *argv)) != 0)
		{
			++argv;
			--argc;
			get_arg(tmp, &f, argv);
		}
		else
		{
			if (open_file() == 0)
				return (NULL);
		}
		++argv;
		--argc;
	}
	return (&f);
}
