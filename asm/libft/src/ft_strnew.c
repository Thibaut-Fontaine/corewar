/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:59:33 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/10 11:20:22 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incl/libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh_str;

	fresh_str = (char *)malloc(sizeof(char) * size + 1);
	if (fresh_str == 0)
		return (NULL);
	ft_bzero(fresh_str, size + 1);
	return (fresh_str);
}
