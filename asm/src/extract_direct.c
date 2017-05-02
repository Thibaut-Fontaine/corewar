/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_direct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:31:28 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 16:13:32 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static char	*extract_label(const char *str)
{
	char	*label;
	int		i;

	i = 2;
	while (str[i] && is_labelchar(str[i]))
		i++;
	if (i == 2)
		return (NULL);
	label = ft_strsub(str, 0, i + 2);
	return(label);
}

static char *extract_number(const char *str)
{
	char	*number;
	int		i;
	int		flag;

	flag = 0;
	if (str[1] == '-')
		flag = 1;
	i = flag ? 2 : 1;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i == (flag ? 2 : 1))
		return (NULL);
	number = ft_strsub(str, 0, i + (flag ? 2 : 1));
	return (number);
}


char	*extract_direct(const char *str)
{
	char	*direct;

	if (str[1] == LABEL_CHAR)
		direct = extract_label(str);
	else
		direct = extract_number(str);
	return (direct);
}
