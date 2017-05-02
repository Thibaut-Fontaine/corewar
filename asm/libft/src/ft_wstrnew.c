/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*fresh_str;

	fresh_str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	if (fresh_str == 0)
		return (NULL);
	ft_bzero(fresh_str, sizeof(wchar_t) * (size + 1));
	return (fresh_str);
}
