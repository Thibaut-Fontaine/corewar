/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:31:06 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/19 02:29:22 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "vm.h"

# define AW				64 * 3 + 1
# define AH				64 + 2
# define IW				60
# define IH				6
# define CW				60
# define CH				4
# define PW				48
# define PH				10
# define WPH			8

# define P1_COLOR 		COLOR_RED
# define P2_COLOR 		COLOR_GREEN
# define P3_COLOR 		COLOR_YELLOW
# define P4_COLOR 		COLOR_BLUE
# define N_COLOR		COLOR_WHITE

typedef struct			s_wlist
{
	WINDOW				*win;
	struct s_wlist		*next;
}						t_wlist;

typedef struct			s_gui
{
	WINDOW				*win_arena;
	WINDOW				*win_vm_info;
	WINDOW				**win_champions;
	t_wlist				*wlist_process;
}						t_gui;

#endif
