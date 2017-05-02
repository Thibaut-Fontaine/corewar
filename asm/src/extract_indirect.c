/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_indirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:55:12 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 15:56:11 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static char	*extract_label(char *str)
{
	char	*label;
	int		i;

	i = 1;
	while (str[i] && is_labelchar(str[i]))
		i++;
	if (i == 1)
		return (NULL);
	label = ft_strsub(str, 0, i + 1);
	return(label);
}

static char *extract_number(char *str)
{
	char	*number;
	int		i;
	int		flag;

	flag = 0;
	if (str[0] == '-')
		flag = 1;
	i = flag ? 1 : 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i == (flag ? 1 : 0))
		return (NULL);
	number = ft_strsub(str, 0, i + (flag ? 1 : 0));
	return (number);
}

char	*extract_direct(char *str)
{
	char	*direct;

	if (str[0] == LABEL_CHAR)
		direct = extract_label(str);
	else
		direct = extract_number(str);
	return (direct);
}
