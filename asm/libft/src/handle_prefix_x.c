/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prefix_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:24 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static int	count_leading_zeroes(char *str)
{
	int leading_zeroes;

	leading_zeroes = 0;
	while (*str == '0')
	{
		leading_zeroes++;
		str++;
	}
	return (leading_zeroes);
}

static int	get_space_needed(char *str, int zero_flag)
{
	int space_needed;

	space_needed = 2;
	space_needed -= ft_strcnt(str, ' ');
	if (space_needed == 2 && zero_flag)
		space_needed -= count_leading_zeroes(str);
	return (ft_max2(0, space_needed));
}

static void	write_prefix(char *str, int zero_flag, int minus_flag)
{
	if (zero_flag)
		str[1] = 'x';
	else if (minus_flag)
	{
		ft_strtrns(str, 2);
		str[0] = '0';
		str[1] = 'x';
	}
	else
	{
		while (*str == ' ')
			str++;
		*(str - 2) = '0';
		*(str - 1) = 'x';
	}
}

static char	*extend_prefix(char *str, int space_needed)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strnew(ft_strlen(tmp) + space_needed);
	ft_strcpy(str + space_needed, tmp);
	str[0] = '0';
	str[1] = 'x';
	free(tmp);
	return (str);
}

void		handle_prefix_x(t_specs *specs)
{
	int	space_needed;

	space_needed = get_space_needed(specs->data, specs->zero);
	if (space_needed)
		specs->data = extend_prefix(specs->data, space_needed);
	else
		write_prefix(specs->data, specs->zero, specs->minus);
}
