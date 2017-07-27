/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/27 16:12:31 by mperronc         ###   ########.fr       */
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
	ret.cycle = 0;
	ret.checks = 0;
	ret.cycle_to_die = CYCLE_TO_DIE;
	return (&ret);
}
