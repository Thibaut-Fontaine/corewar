/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 06:37:33 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/10 06:41:37 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_number32(int fhandle, unsigned int number)
{
	unsigned int tmp;

	tmp = number >> 24;
	write(fhandle, &tmp, 1);
	tmp = number >> 16;
	write(fhandle, &tmp, 1);
	tmp = number >> 8;
	write(fhandle, &tmp, 1);
	write(fhandle, &number, 1);
}

void	write_number16(int fhandle, unsigned short number)
{
	unsigned short tmp;

	tmp = number >> 8;
	write(fhandle, &tmp, 1);
	write(fhandle, &number, 1);
}
