/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/28 06:28:56 by tfontain         ###   ########.fr       */
/*   Updated: 2017/07/27 16:22:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static inline char		*to_memory(const char *arg,
		t_header *champs, int n_players, unsigned int n)
{
	static char			arena[MEM_SIZE] = {0};

	open_file(arg, arena + (MEM_SIZE / n_players) * n, champs + n);
	return (arena);
}

t_argv					*parse(int ac, const char *av[])
{
	static t_argv		ret;
	unsigned int		ch_number;
	//t_ch				champs[MAX_PLAYERS];
	//const char			*pl[MAX_PLAYERS] = {0};
	unsigned int		n;
	int					binary_n;

	n = 0;
	++av;
	--ac;
	ft_bzero(&ret, sizeof(ret));
	ret.n_champs = count_champions(ac, av, &binary_n); //
	ret.n_champs > MAX_PLAYERS ? error(_ERR_TOO_MANY_CH)() : 0;
	ret.n_champs == 0 ? error(_ERR_USAGE)() : 0;
	//ft_bzero(champs, sizeof(t_ch) * MAX_PLAYERS);
	ch_number = 0;
	while (ac > 0)
	{
		if ((*av)[0] == '-' && (*av)[2] == 0)
		{
			if ((*av)[1] == 'n' || (*av)[1] == 's' || (*av)[1] == 'd')
			{
				if ((*av)[1] == 'n')
					n = ft_atoi(av[1]);
				else
					ret.f.flag |= ((*av)[1] == 'd' ? _D_ : _S_);
				--ac;
				++av;
			}
			else if ((*av)[1] == 'g')
				ret.f.flag |= _G_;
		}
		else
		{
			ret.arena = to_memory(*av, ret.champ, ret.n_champs, ch_number++);
			/*
			if (1 <= n && n <= MAX_PLAYERS)
				pl[n] = *av; // binary_n
			pl[ch_number] = *av; // tout enregistrer ici, puis trier et mem
			*/
		}
		++av;
		--ac;
	}
	if (ret.f.flag & _G_)
		ret.color = init_color_arena(&ret);
	ret.ref_tab = get_ref_tab();
	ret.cycle = 0;
	ret.checks = 0;
	ret.cycle_to_die = CYCLE_TO_DIE;
	return (&ret);
}
