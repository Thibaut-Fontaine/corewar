/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:23:44 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:32:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t		ft_putnstr_fdr(char const *s, size_t n, int fd)
{
	size_t	len;

	if (s == NULL)
		return (-1);
	return (write(fd, s, ((len = ft_strlen(s)) > n ? n : len)));
}
