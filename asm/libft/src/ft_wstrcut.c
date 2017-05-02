/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:09 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

wchar_t	*ft_wstrcut(wchar_t *str, int n)
{
	wchar_t *tmp;

	tmp = ft_wstrdup(str);
	free(str);
	str = ft_wstrnew(n);
	ft_wstrncpy(str, tmp, n);
	free(tmp);
	return (str);
}
