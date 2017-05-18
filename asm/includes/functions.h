/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 17:45:57 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void			write_args(int fd, t_oplist *op, size_t b_wr, t_asm *tasm);
void			write_octalcoding(int fhandle, t_oplist *op);
void			write_op(int fhandle, t_oplist *op, t_asm *tasm);
void			write_number(int handle, unsigned int number, size_t size);
void			write_code(int fhandle, t_asm *tasm);
void			write_header(int fhandle, t_asm *tasm);
void			generate_bytecode(t_asm *tasm, char *file);
void			check_param_number(t_arglist *args, t_asm *obj,
	t_parser *parser, int num);
void			check_param_error(t_oplist *op, t_asm *obj, t_parser *parser,
	t_param_parser p);
void			check_labels_error(t_labellist *labellist, t_oplist *oplist,
	t_asm *obj, t_parser *parser);
void			check_param_type(t_arglist *arg, int type, t_asm *obj,
	t_parser *parser);
void			check_empty_obj(t_oplist *oplist, t_asm *obj, t_parser *parser);
char			***init_optab(void);
void			add_operation(t_oplist **oplist, t_parser *parser, char *str,
	t_asm *obj);
void			add_label_to_list(t_labellist **labellist, t_asm *obj,
	t_parser *parser, char *name);
void			add_argument(t_arglist *current, t_arglist **arglist);
int				is_labelchar(const char c);
void			remove_com(char **line, t_asm *obj, t_parser *parser);
void			asm_init(t_asm *obj);
t_param_parser	*param_parser_init(void);
void			ft_error(char *str, t_parser *parser, t_asm *obj);
void			format_error(char *str, t_asm *obj, t_parser *parser);
void			label_error(char *str, int i, t_asm *obj, t_parser *parser);
void			param_error(t_arglist *arg, int type, t_asm *obj,
	t_parser *parser);
void			expected_type(int type);
t_arglist		*extract_params(t_parser *parser, t_asm *obj);
void			extract_instruction(t_oplist **oplist, t_parser *parser,
	t_asm *obj);
void			extract_labeldecl(t_labellist **labellist, t_asm *obj,
	t_parser *parser);
int				get_operation_type(char *str, t_parser *parser);
uint32_t		get_op_size(t_oplist *op, t_parser *parser, t_param_parser p);
int				get_arg_type(t_parser *parser);
void			parse_name(t_asm *obj, t_parser *parser);
void			parse_comment(t_asm *obj, t_parser *parser);
int				parse_header(t_asm *obj, t_parser *parser);
t_arglist		*parse_argument(t_parser *parser, t_asm *obj);
t_asm			parse(char *av);
void			free_asm(t_asm *obj);
void			free_oplist(t_oplist *ops);
void			free_arglist(t_arglist *args);
void			free_labellist(t_labellist *labels);
void			free_optab(char ***optab);
void			free_parser(t_parser *parser);
char			*replace_filename(char *name);

#endif
