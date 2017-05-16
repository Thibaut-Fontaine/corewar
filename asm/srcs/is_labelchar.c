/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_labelchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:03:57 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:10 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_labelchar(const char c)
{
	return (ft_strchr(LABEL_CHARSET, c) ? 1 : 0);
}
