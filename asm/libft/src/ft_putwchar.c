/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:05 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static char	*get_right_mask(size_t wclen)
{
	if (wclen <= 7)
		return ("0xxxxxxx");
	else if (wclen <= 11)
		return ("110xxxxx 10xxxxxx");
	else if (wclen <= 16)
		return ("1110xxxx 10xxxxxx 10xxxxxx");
	else
		return ("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
}

static char	*fill_mask(char *mask, char *binwc)
{
	char	*startmask;
	char	*startbinwc;

	startmask = mask;
	startbinwc = binwc;
	while (*(mask + 1))
		mask++;
	while (*(binwc + 1))
		binwc++;
	while (mask >= startmask)
	{
		if (*mask == 'x' && binwc >= startbinwc)
		{
			*mask = *binwc;
			binwc--;
		}
		else if (*mask == 'x')
			*mask = '0';
		mask--;
	}
	return (startmask);
}

static int	bintodec(char *bin)
{
	int		ret;

	ret = 0;
	while (*bin == '0')
		bin++;
	while (*bin)
	{
		ret = ret * 2;
		if (*bin == '1')
			ret++;
		bin++;
	}
	return (ret);
}

void		free_everything(char **chartab, char *binwc, char *masktouse)
{
	int i;

	free(binwc);
	free(masktouse);
	i = 0;
	while (chartab[i])
	{
		free(chartab[i]);
		i++;
	}
	free(chartab);
}

int			ft_putwchar(wchar_t wc)
{
	char	*masktouse;
	char	*binwc;
	char	**chartab;
	int		c;
	int		i;

	binwc = ft_uitoa_base16(wc, 2);
	masktouse = ft_strdup(get_right_mask(ft_strlen(binwc)));
	masktouse = fill_mask(masktouse, binwc);
	chartab = ft_strsplit(masktouse, ' ');
	i = 0;
	while (chartab[i])
	{
		c = bintodec(chartab[i]);
		write(1, &c, 1);
		i++;
	}
	free_everything(chartab, binwc, masktouse);
	return (i);
}
