/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extracts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:18:02 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 18:19:36 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

static void	test_extract(char *expected, char *str, char * (*f)(const char *))
{
	char	*ret;

	ret = f(str);
	if (!ret && !expected)
		ft_printf("Test %-40s OK\n", str);
	else if ((!ret && expected) || (ret && !expected) || ft_strcmp(ret, expected))
		ft_printf("Test %-40s KO : got %s expected %s\n", str, ret, expected);
	else
		ft_printf("Test %-40s OK\n", str);
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
	test_extract(".name", ".name\t", &extract_command);
	test_extract(".name", ".name wololo", &extract_command);
	test_extract(".comment", ".comment lmao", &extract_command);
	test_extract(".name", ".namecommand", &extract_command);
	test_extract(NULL, "", &extract_command);
	test_extract(NULL, ".", &extract_command);

	ft_printf("\n === EXTRACT STRING TESTS ===\n");
	test_extract("\"Wololo\"", "\"Wololo\"", &extract_string);
	test_extract("\"Wololo ayy lmao\t\1\"", "\"Wololo ayy lmao\t\1\"", &extract_string);
	test_extract(NULL, "\"Wololo", &extract_string);
	test_extract(NULL, "\"a", &extract_string);
	test_extract("\"\"", "\"\"", &extract_string);

	ft_printf("\n === EXTRACT DIRECT TESTS ===\n");
	test_extract("%10", "%10", &extract_direct);
	test_extract("%-42", "%-42", &extract_direct);
	test_extract("%42", "%42lmao", &extract_direct);
	test_extract("%-42", "%-42lmao", &extract_direct);
	test_extract("%:toto", "%:toto", &extract_direct);
	test_extract(NULL, "%-label", &extract_direct);
	test_extract(NULL, "%:", &extract_direct);
	test_extract(NULL, "%label", &extract_direct);
	test_extract("%:toto", "%:toto sans blague", &extract_direct);

	ft_printf("\n === EXTRACT INDIRECT TESTS ===\n");
	test_extract("10", "10", &extract_indirect);
	test_extract("-42", "-42", &extract_indirect);
	test_extract("42", "42lmao", &extract_indirect);
	test_extract("-42", "-42lmao", &extract_indirect);
	test_extract(":toto", ":toto", &extract_indirect);
	test_extract(NULL, "-label", &extract_indirect);
	test_extract(NULL, ":", &extract_indirect);
	test_extract(NULL, "label", &extract_indirect);
	test_extract(":toto", ":toto sans blague", &extract_indirect);

	generate_op_from_line("live: sti ", NULL, NULL);
/*
	ft_printf("\n === EXTRACT OP TESTS ===\n");
	test_extract("add", "add ", &extract_op);
	test_extract("add", "add  llmao", &extract_op);
	test_extract(NULL, "a:lmao ", &extract_op);
	test_extract("a123", "a123 et des patetes", &extract_op);
	test_extract("sti123", "sti123", &extract_op);

	ft_printf("\n === EXTRACT LABELDECL TESTS ===\n");
	test_extract("a:", "a:lmao ", &extract_labeldecl);
	test_extract("a:", "a: lmao ", &extract_labeldecl);
	test_extract("error", "a&toto:lmao ", &extract_labeldecl);
	test_extract("1233:", "1233:lmao ", &extract_labeldecl);
	test_extract("error", "tutu", &extract_labeldecl);*/
	return (0);
}
