/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:48:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/26 13:24:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

uint16_t	ft_swap_uint16(uint16_t val, t_bool is_signed)
{
	if (is_signed)
		return (val << 8) | ((val >> 8) & 0xFF);
	return (val << 8) | (val >> 8);
}

uint32_t	ft_swap_uint32(uint32_t val, t_bool is_signed)
{
	if (is_signed)
	{
		val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
		return (val << 16) | ((val >> 16) & 0xFFFF);
	}
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

uint64_t	ft_swap_uint64(uint64_t val, t_bool is_signed)
{
	if (is_signed)
	{
		val = ((val << 8) & 0xFF00FF00FF00FF00ULL) |
			((val >> 8) & 0x00FF00FF00FF00FFULL);
		val = ((val << 16) & 0xFFFF0000FFFF0000ULL) |
			((val >> 16) & 0x0000FFFF0000FFFFULL);
		return (val << 32) | ((val >> 32) & 0xFFFFFFFFULL);
	}
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL) |
		((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL) |
		((val >> 16) & 0x0000FFFF0000FFFFULL);
	return (val << 32) | (val >> 32);
}

uintmax_t	ft_endian(uintmax_t val, t_bool is_signed)
{
	if (val <= 0xFF)
		return (val);
	else if (val <= 0xFFFF)
		val = ft_swap_uint16(val, is_signed);
	else if (val <= 0xFFFFFFFF)
		val = ft_swap_uint32(val, is_signed);
	else if (val <= 0xFFFFFFFFFFFFFFFF)
		val = ft_swap_uint64(val, is_signed);
	return (val);
}
