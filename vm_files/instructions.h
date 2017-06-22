/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:33:30 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/22 18:08:23 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

typedef struct		s_instruct
{
	int				size;
	char			opcode;
	int				*args;
	int				*types;
}					t_instruct;

#endif
