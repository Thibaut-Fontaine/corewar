/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:50:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/23 04:56:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

#include "structs.h"

int			count_live(int i, int reset);
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


int			live(int direct);
int			st(t_process *proc, t_instruct *instruct, char *arena);
int			add(t_process *proc, t_instruct *instruct);
int			sub(t_process *proc, t_instruct *instruct);
int 		ld(t_process *proc, t_instruct *instruct, char *arena);
int 		lld(t_process *proc, t_instruct *instruct, char *arena);
int 		ldi(t_process *proc, t_instruct *instruct, char *arena);
int 		lldi(t_process *proc, t_instruct *instruct, char *arena);
int 		frk(t_plst *self, t_plst *head, t_instruct *instruct);
int 		lfork(t_plst *self, t_plst *head, t_instruct *instruct);
int 		aff(t_process *proc, t_instruct *instruct);

int			run(t_argv info);


#endif
