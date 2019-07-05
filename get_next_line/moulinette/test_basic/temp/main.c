/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:24:57 by lle-blev          #+#    #+#             */
/*   Updated: 2019/07/03 15:44:06 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tests.h"

int		main( void ) {

printf("------------------------------------------------------------------------\n");
printf("	----------		TEST_SIMPLE		----------\n");
printf("------------------------------------------------------------------------\n");
	int	out = test_simple();
printf("	----------		MAIN RETURN		----------\n");
printf("	int out = [%d] = test_simple(void)\n", out);
printf("------------------------------------------------------------------------\n");
printf("	----------		TEST_FDS		----------\n");
printf("------------------------------------------------------------------------\n");
	int	fd = test_fds();
printf("	----------		MAIN RETURN		----------\n");
printf("	int fd = [%d] = test_fds(void)\n", fd);
printf("------------------------------------------------------------------------\n");
	return (0);
}