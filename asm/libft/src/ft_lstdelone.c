/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:54:47 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}
