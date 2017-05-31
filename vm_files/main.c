/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:22:42 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 03:03:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
**   ██╗   ██ ██ ██████╗████████ ██╗   ██ ╗█████╗ ██╗
**   ██║   ██ ██ ██╔══██╚══██╔══ ██║   ██ ██╔══██ ██║
**   ██║   ██ ██ ██████╔╝  ██║   ██║   ██ ███████ ██║
**   ╚██╗ ██╔ ██ ██╔══██╗  ██║   ██║   ██ ██╔══██ ██║
**    ╚████╔╝ ██ ██║  ██║  ██║   ╚██████╔ ██║  ██ ███████╗
**     ╚═══╝  ╚═ ╚═╝  ╚═╝  ╚═╝    ╚═════╝ ╚═╝  ╚═ ╚══════╝
**                    ███╗   ███ ╗█████╗  ██████ ██╗  ██ ██ ███╗   ██ ███████╗
**                    ████╗ ████ ██╔══██ ██╔════ ██║  ██ ██ ████╗  ██ ██╔════╝
**                    ██╔████╔██ ███████ ██║     ███████ ██ ██╔██╗ ██ █████╗
**                    ██║╚██╔╝██ ██╔══██ ██║     ██╔══██ ██ ██║╚██╗██ ██╔══╝
**                    ██║ ╚═╝ ██ ██║  ██ ╚██████ ██║  ██ ██ ██║ ╚████ ███████╗
**  by tfontain       ╚═╝     ╚═ ╚═╝  ╚═ ╝╚═════ ╚═╝  ╚═ ╚═ ╚═╝  ╚═══ ╚══════╝
*/

int			main(int argc, const char *argv[])
{
	t_argv	*all;

	all = parse(argc, argv);
	save_ch_names(all->champ);
	introducing_contestants(all->n_champs, all->champ);
	run(*all);
	display_winner(2, all->champ);
	return (0);
}
