/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:50:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/24 19:06:01 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

# include "structs.h"

int			mod(int n, int d);
float		ft_sqrt(float num);
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
int			store_at(char *arena, int i, int val);
int			extract_at(char *arena, int addr);
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

int			op_live(t_process *proc, t_instruct *i);
int			op_ld(t_process *proc, t_instruct *instruct, char *arena);
int			op_st(t_process *proc, t_instruct *ins, char *arena, char *color);
int			op_add(t_process *proc, t_instruct *instruct);
int			op_sub(t_process *proc, t_instruct *instruct);
int			op_and(t_process *proc, t_instruct *i, char *arena);
int			op_or(t_process *proc, t_instruct *i, char *arena);
int			op_xor(t_process *proc, t_instruct *i, char *arena);
int			op_zjmp(t_process *proc, char *arena);
int			op_ldi(t_process *proc, t_instruct *instruct, char *arena);
int			op_sti(t_process *proc, t_instruct *i, char *arena, char *color);
int			op_lld(t_process *proc, t_instruct *instruct, char *arena);
int			op_lldi(t_process *proc, t_instruct *instruct, char *arena);
int			op_lfork(t_plst *self, t_plst **head, t_instruct *instruct);
int			op_fork(t_plst *self, t_plst **head, t_instruct *instruct);
int			op_aff(t_process *proc, t_instruct *instruct);

int			run(t_argv *info);

void		gui(t_argv *all, t_plst *head);
void		free_gui(t_argv *all);
char		*init_color_arena(t_argv *all);
char		*op(int opcode);
char		*types(int type);
void		write_color(char *color, int index, char id);
void		refresh_display(t_argv *all, t_plst *head);
void		refresh_champion(t_header *champ, WINDOW *win, int i);
void		refresh_info(t_argv *all, WINDOW *win);
void		refresh_process(WINDOW *win, WINDOW *arena, t_process *proc);
void		refresh_arena(char *arena, char *color, WINDOW *win);
void		refresh_wlist(t_plst *plst, t_argv *all);
t_wlist		*build_wlist(t_plst *plst);

#endif
