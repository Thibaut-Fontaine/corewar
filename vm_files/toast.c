/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 01:31:24 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/02 01:34:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("%u, %lu\n", HEADER_LENGTH, PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(unsigned int) * 2);
	return 0;
}
