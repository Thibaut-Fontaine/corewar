/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/09 19:38:03 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "asm.h"

char	***init_optab(void);
t_asm	*make_example_asm(void);
void	generate_bytecode(t_asm *tasm, char *file);
void	write_header(int fhandle, t_header *header);

#endif
