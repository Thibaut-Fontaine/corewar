/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:23:44 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 11:38:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t		ft_putstr_fdr(char const *s, int fd)
{
	if (s == NULL)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
