/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:29:40 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 10:49:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	char	*line = NULL;
	int		x = 1;
	int		fd = open("./test.txt", O_RDONLY);
	/* int		fd = open("./empty.txt", O_RDONLY); */

	while (x > 0)
	{
		x = get_next_line(1600, &line);
		printf("[%d] line: %s\n", x, line);
		ft_strdel(&line);
		line = NULL;
	}
	close(fd);
	return (0);
}
