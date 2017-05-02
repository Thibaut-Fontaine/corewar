/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extracts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:18:02 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:13:41 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static void	test_extract(char *expected, char *str, char * (*f)(const char *))
{
	char	*ret;

	ret = f(str);
	printf("EXPECTED :\n%s\nRESULT :\n%s\n\n", expected, ret);
}

int		main(void)
{
	printf(" === EXTRACTOR FUNCTIONS TESTS === \n\n");

	printf(" === EXTRACT REGISTER TESTS === n\n\n");
	test_extract("r1", "r1 sti add", &extract_register);

	return (0);
}
