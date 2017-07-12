/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:31:06 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/12 23:30:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "vm.h"

# define ARENA_W		64 * 3 + 1
# define ARENA_H		64 + 2
# define INFO_W			48
# define INFO_H			8
# define CHAMP_W		48
# define CHAMP_H		8
# define PROC_W			48
# define PROC_H			13

# define P1_COLOR 		COLOR_RED
# define P2_COLOR 		COLOR_GREEN
# define P3_COLOR 		COLOR_YELLOW
# define P4_COLOR 		COLOR_BLUE
# define N_COLOR		COLOR_WHITE

typedef struct	s_gui
{
	WINDOW 	*win_arena;
	WINDOW 	*win_vm_info;
	WINDOW 	**win_champions;
	char	*color;
}				t_gui;

#endif
