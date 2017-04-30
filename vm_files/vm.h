/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:25 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/30 02:48:07 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "./op.h"

/*
** argv parsing flags.
** -
** simple exemple :
** flag = _b | _stealth; ((flag & (1 << 4)) != 0 && (flag & (1 << 6)) != 0) ?..
*/

# define _a_ (1 << 0)

# define _d_ (1 << 1)
# define _s_ (1 << 2)
# define _v_ (1 << 3)

# define _b_ (1 << 4)
# define _n_ (1 << 5)

# define _stealth_ (1 << 6)


typedef struct
{
	int			flag;
	int			nd;
	int			ns;
	int			nv;
}				t_opt;

#endif
