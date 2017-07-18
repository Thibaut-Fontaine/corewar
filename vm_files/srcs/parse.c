/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/18 19:46:30 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>
*/

static inline int		ret_flag(char c)
{
	if (c == 'a')
		return (0);
	else if (c == 'd')
		return (_D_);
	else if (c == 's')
		return (_S_);
	else if (c == 'v')
		return (_V_);
	else if (c == 'b')
		return (_B_);
	else if (c == 'n')
		return (_N_);
	else
		return (0);
}

static inline int		fill_flag(t_opt *f, const char *c)
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

static inline int		get_arg(int i, t_opt *f, const char *argv[])
{
	if (i == _D_)
		return (f->nd = ft_atoi(*argv));
	else if (i == _S_)
		return (f->ns = ft_atoi(*argv));
	else if (i == _V_)
		return (f->nv = ft_atoi(*argv));
	else if ((i == _B_ || i == _N_) && ft_strequ(*argv, "--stealth"))
		f->flag |= _STEALTH_;
	return (-1);
}

static inline char		*champion_to_memory(const char *arg,
		t_header *current_champ, int n_players)
{
	char			*ptchamp;
	char			*arena;
	t_header		*tofree;

	arena = generate_memory(&ptchamp, n_players);
	tofree = open_file(arg, ptchamp);
	*current_champ = *tofree;
	free(tofree);
	return (arena);
}

static char				*init_color_arena(t_argv *all)
{
	int				i;
	unsigned int	j;
	char			*color;

	color = ft_strnew(MEM_SIZE);
	i = 0;
	while (i < all->n_champs)
	{
		j = 0;
		while (j < all->champ[i].prog_size)
		{
			color[j + ((MEM_SIZE / all->n_champs) * i)] = i + 1;
			j++;
		}
		i++;
	}
	return (color);
}

t_argv					*parse(int argc, const char *argv[])
{
	int				tmp;
	static t_argv	ret;

	ft_bzero(&ret, sizeof(ret));
	--argc;
	++argv;
	ret.n_champs = count_champions(argc, argv);
	if (ret.n_champs > MAX_PLAYERS)
		error(_ERR_TOO_MANY_CH)();
	ret.n_champs == 0 ? error(_ERR_USAGE)() : 0;
	while (argc)
	{
		if (argc >= 2 && (tmp = fill_flag(&ret.f, *argv)) != 0)
		{
			if (get_arg(tmp, &ret.f, argv) != -1)
			{
				++argv;
				--argc;
			}
		}
		else
			ret.arena = champion_to_memory(*argv, ret.champ + champ_num(C_),
					ret.n_champs);
		++argv;
		--argc;
	}
	if (ret.f.flag & _N_)
		ret.color = init_color_arena(&ret);
	ret.ref_tab = get_ref_tab();
	return (&ret);
}
