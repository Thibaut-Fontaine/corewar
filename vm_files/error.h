/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 01:43:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/02 02:27:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define _ERR_MAGIC_NUMBER 1
# define _ERR_SOURCE_FILE 2
# define _ERR_USAGE 3
# define _ERR_CSIZE_DIFFER 4
# define _ERR_CH_TOO_SMALL 5
# define _ERR_STDERROR 6

void	exit_perror(const char *name);
void	usage(void);
void	bad_source_file(const char *name);
void	bad_magic_number(const char *name);
void	code_size_differ(const char *name);
void	champion_too_small(const char *name);

#endif
