/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/10 06:54:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "asm.h"

char	***init_optab(void);
t_asm	*make_example_asm(void);
void	generate_bytecode(t_asm *tasm, char *file);
void	write_header(int fhandle, t_asm *tasm);
void	write_code(int fhandle, t_asm *tasm);
void	write_octalcoding(int fhandle, t_oplist *op);
void	write_number32(int fhandle, unsigned int number);
void	write_number16(int fhandle, unsigned short number);
void	write_args(int fd, t_arglist *args, size_t bytes_written, t_asm *tasm);

#endif
