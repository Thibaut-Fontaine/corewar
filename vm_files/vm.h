/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:25 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/01 23:08:04 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "./op.h"

/*
** allowed funcs :
** ◦ open
** ◦ read
** ◦ write
** ◦ lseek
** ◦ close
** ◦ malloc
** ◦ realloc
** ◦ free
** ◦ exit
** ◦ perror / strerror (et, du coup, errno)
*/

unsigned char		*open_file(const char *name, int *len);

void				usage(void);
void				bad_source_file(const char *name);
void				bad_magic_number(const char *name);
void				close_error(const char *name);

/*
** argv parsing flags.
** -
** simple example :
** flag = _b | _stealth; ((flag & (1 << 4)) != 0 && (flag & (1 << 6)) != 0) ?..
*/

# define _A_ (1 << 0)
# define _D_ (1 << 1)
# define _S_ (1 << 2)
# define _V_ (1 << 3)
# define _B_ (1 << 4)
# define _N_ (1 << 5)
# define _STEALTH_ (1 << 6)

typedef struct
{
	int				flag;
	int				nd;
	int				ns;
	int				nv;
}					t_opt;

typedef struct
{
	t_header		info;
	unsigned char	*prog;
}					t_file;

# define _

#endif
