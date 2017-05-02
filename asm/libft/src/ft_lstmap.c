/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:15:31 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flst;

	flst = NULL;
	if (lst)
	{
		flst = ft_lstnew(lst->content, lst->content_size);
		if (!flst)
			return (NULL);
		flst = (*f)(flst);
		flst->next = ft_lstmap(lst->next, (*f));
	}
	return (flst);
}
