/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:42:42 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 15:53:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strnchr(const char *s, int c, size_t n)
{
	size_t		k;

	k = 0;
	while (s[k] != (char)c && s[k] != '\0' && k < n)
		++k;
	if (s[k] != (char)c || k == n)
		return (NULL);
	return ((char*)s + k);
}
