/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:50:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/18 17:59:03 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

#include "structs.h"

int			mod(int n, int d);
int			check_register(t_instruct *i);
int			*last_living_player(void);
int			*flags(void);
int			n_champ(int n);
int			count_live(int reset);
t_argv		*parse(int argc, const char *argv[]);
int			is_there_flag(t_opt flag, int which);
void		save_ch_names(t_header ch[MAX_PLAYERS]);
int			champ_num(int reset);
char		*generate_memory(char **arena_pt, int n_players);
t_header	*open_file(const char *name, char *prog);
int			count_champions(int argc, const char *argv[]);
t_champion	*get_champion(void);

void		introducing_contestants(int n_champs, t_header champ[MAX_PLAYERS]);
void		display_winner(int champ_number, t_header champ[MAX_PLAYERS]);
void		display_live(int ch_number, t_champion champ[MAX_PLAYERS]);
void		dump(char *arena);

t_instruct	*check_operation(char *arena, t_process *proc, int **tab);
void		get_args(t_process *prc, char *arena, int *tab, t_instruct *ins);
int			extract_dir(t_process *prc, t_instruct *ins, char *arena, int *tab);
int			extract_ind(t_process *proc, t_instruct *instruct, char *arena);
int			extract_reg(t_process *proc, t_instruct *instruct, char *arena);

int			is_valid_reg(int reg);
int 		store_at(char *arena, int i, int val);
int 		extract_at(char *arena, int addr);
int			swap_32int(int num);
int			**get_ref_tab(void);
void		fork_process(t_plst **head, t_plst *to_fork, int pc);
t_plst		*init_process(t_argv info);
int			process_live(t_plst **head);
void		free_instruction(t_instruct *instruct);

/*
** op_value is used to get value from direct, indirect or register
** op_stock is used to fill a value in an indirect or in a register
*/

int			op_value(t_process *proc, char *arena, int n, int idx);
//void		*op_stock(t_process *proc, t_instruct *i, char *arena, int n);

int			_live(t_process *proc, t_instruct *i);
int 		_ld(t_process *proc, t_instruct *instruct, char *arena);
int			_st(t_process *proc, t_instruct *instruct, char *arena, char *color);
int			_add(t_process *proc, t_instruct *instruct);
int			_sub(t_process *proc, t_instruct *instruct);
int			_and(t_process *proc, t_instruct *i, char *arena);
int			_or(t_process *proc, t_instruct *i, char *arena);
int			_xor(t_process *proc, t_instruct *i, char *arena);
int			_zjmp(t_process *proc, char *arena);
int 		_ldi(t_process *proc, t_instruct *instruct, char *arena);
int			_sti(t_process *proc, t_instruct *i, char *arena, char *color);
int 		_lld(t_process *proc, t_instruct *instruct, char *arena);
int 		_lldi(t_process *proc, t_instruct *instruct, char *arena);
int 		_lfork(t_plst *self, t_plst **head, t_instruct *instruct);
int 		_fork(t_plst *self, t_plst **head, t_instruct *instruct);
int 		_aff(t_process *proc, t_instruct *instruct);

int			run(t_argv *info);

void		gui(t_argv *all, t_plst *head);
void		write_color(char *color, int index, char id);
void		refresh_display(t_argv *all, t_plst *head);

#endif
