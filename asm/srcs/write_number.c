/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 06:37:33 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/11 17:39:40 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	write_number32(int fhandle, unsigned int number)
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

static void	write_number16(int fhandle, unsigned short number)
{
	unsigned short tmp;

	tmp = number >> 8;
	write(fhandle, &tmp, 1);
	write(fhandle, &number, 1);
}

void	write_number(int handle, unsigned int number, size_t size)
{
	if (size == 2)
		write_number16(handle, (unsigned short) number);
	else if (size == 4)
		write_number32(handle, number);
}
