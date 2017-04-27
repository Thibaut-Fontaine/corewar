/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:35:55 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/06 12:29:51 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstreplace(t_list *previous, t_list *new)
{
	t_list		*to_erase;

	to_erase = previous->next;
	new->next = to_erase->next;
	previous->next = new;
	free(to_erase->content);
	free(to_erase);
	return (new);
}
