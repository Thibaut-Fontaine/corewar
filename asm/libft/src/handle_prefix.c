/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:23 by mperronc          #+#    #+#             */
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

	space_needed = 1;
	space_needed -= ft_strcnt(str, ' ');
	if (space_needed == 1 && zero_flag)
		space_needed -= count_leading_zeroes(str);
	return (ft_max2(0, space_needed));
}

static void	write_prefix(char *str, int zero_flag, int minus_flag, char c)
{
	if (zero_flag)
		str[0] = c;
	else if (minus_flag)
	{
		ft_strtrns(str, 1);
		str[0] = c;
	}
	else
	{
		while (*str == ' ')
			str++;
		*(str - 1) = c;
	}
}

static char	*extend_prefix(char *str, int space_needed, char c)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strnew(ft_strlen(tmp) + space_needed);
	ft_strcpy(str + space_needed, tmp);
	str[0] = c;
	free(tmp);
	return (str);
}

void		handle_prefix(t_specs *specs, char c)
{
	int	space_needed;

	space_needed = get_space_needed(specs->data, specs->zero);
	if (space_needed)
		specs->data = extend_prefix(specs->data, space_needed, c);
	else
		write_prefix(specs->data, specs->zero, specs->minus, c);
}
