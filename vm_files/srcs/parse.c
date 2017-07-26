/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/26 21:53:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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

t_argv				*parse(int ac, const char *av[])
{
	static t_argv	ret;

	++av;
	--ac;
	ret.n_champs = count_champions(ac, av);
	ret.n_champs > MAX_PLAYERS ? error(_ERR_TOO_MANY_CH)() : 0;
	ret.n_champs == 0 ? error(_ERR_USAGE)() : 0;
	while (ac > 0)
	{
		if ((*av)[0] == '-' && (*av)[2] == 0)
		{
			if ((*av)[1] == 'n' || (*av)[1] == 's' || (*av)[1] == 'd')
			{
				if (ac == 1)
					error(_ERR_USAGE)();
				if ((*av)[1] == 'n')
					; // n. du champion
				else // si 's' ou 'd'
					ret.f.flag |= ((*av)[1] == 'd' ? _D_ : _S_);
				--ac;
				++av;
			}
			else if ((*av)[1] == 'g')
				ret.f.flag |= _G_;
		}
		else
			ret.arena = champion_to_memory(*av, ret.champ + champ_num(C_),
					ret.n_champs);
		--ac;
		++av;
	}
	if (ret.f.flag & _G_)
		ret.color = init_color_arena(&ret);
	ret.ref_tab = get_ref_tab();
	return (&ret);
}

// OLD:
/*inline int		ret_flag(char c)
{
	if (c == 'g')
		return (_G_);
	else if (c == 's')
		return (_S_);
	else if (c == 'n')
		return (_N_);
	else if (c == 'd')
		return (_D_);
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
	else if (i == _N_)
		return (f->nn = ft_atoi(*argv));
	else if (i == _G_)
		return (0);
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
	if (ret.f.flag & _G_)
		ret.color = init_color_arena(&ret);
	ret.ref_tab = get_ref_tab();
	return (&ret);
}*/
