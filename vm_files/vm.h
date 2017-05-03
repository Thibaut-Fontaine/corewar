/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:25 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/03 21:19:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "./op.h"
# include "./error.h"

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

typedef struct
{
	t_header		info;
	unsigned char	*prog;
}					t_file;

typedef void		(*t_error)();

t_file				*open_file(const char *name, int *len);
t_error				error(int err);

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

typedef unsigned int uint;

# define _
# define U_ sizeof(unsigned int)
# define PROG_NAME_LEN_0 (PROG_NAME_LENGTH + sizeof(char))
# define COMMENT_LEN_0 (COMMENT_LENGTH + sizeof(char))
# define PADDING_PROGN (U_ - PROG_NAME_LEN_0 % U_)
# define PADDING_CMT (U_ - COMMENT_LEN_0 % U_)
# define PADDING (PADDING_PROGN + PADDING_CMT)
# define HEADER_LENGTH (PROG_NAME_LEN_0 + COMMENT_LEN_0 + U_ * 2 + PADDING)

#endif
