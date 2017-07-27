/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:47:44 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/27 14:37:07 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define _D_ (1 << 0)
# define _S_ (1 << 1)
# define _G_ (1 << 2)
# define _N_ (1 << 3)

# define MAX_BYTES_PER_PLAYER (MEM_SIZE / MAX_PLAYERS)
# define U_ sizeof(unsigned int)
# define PROG_NAME_LEN_0 (PROG_NAME_LENGTH + sizeof(char))
# define COMMENT_LEN_0 (COMMENT_LENGTH + sizeof(char))
# define PADDING_PROGN (U_ - PROG_NAME_LEN_0 % U_)
# define PADDING_CMT (U_ - COMMENT_LEN_0 % U_)
# define PADDING (PADDING_PROGN + PADDING_CMT)
# define HEADER_LENGTH (PROG_NAME_LEN_0 + COMMENT_LEN_0 + U_ * 2 + PADDING)

# define CHMAX CHAMP_MAX_SIZE
# define COM_L COMMENT_LENGTH
# define PRGM PROG_NAME_LENGTH

#endif
