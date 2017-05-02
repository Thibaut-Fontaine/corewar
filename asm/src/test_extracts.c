/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extracts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:18:02 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 17:12:43 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static void	test_extract(char *expected, char *str, char * (*f)(const char *))
{
	char	*ret;

	ret = f(str);
	if (!ret && !expected)
		ft_printf("Test %-20s OK\n", str);
	else if ((!ret && expected) || (ret && !expected) || ft_strcmp(ret, expected))
		ft_printf("Test %-20s KO : got %s\n", str, ret);
	else
		ft_printf("Test %-20s OK\n", str);
	if (ret)
		free(ret);
}

int		main(void)
{
	ft_printf(" === EXTRACTOR FUNCTIONS TESTS ===\n\n");

	ft_printf(" === EXTRACT REGISTER TESTS ===\n");
	test_extract("r1", "r1 sti add", &extract_register);
	test_extract("r23", "r23abc", &extract_register);
	test_extract(NULL, "rabc", &extract_register);
	test_extract(NULL, "r", &extract_register);
	test_extract(NULL, "", &extract_register);

	ft_printf("\n === EXTRACT COMMAND TESTS ===\n");
	test_extract(".name", ".name", &extract_command);
	test_extract(".comment", ".comment", &extract_command);
	test_extract(".name", ".name\t\t", &extract_command);
	test_extract(".name", ".name wololo", &extract_command);
	test_extract(".comment", ".comment lmao", &extract_command);
	test_extract(".name", ".namecommand", &extract_command);
	test_extract(NULL, "", &extract_command);

	return (0);
}
