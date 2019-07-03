/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:29:40 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/02 15:29:50 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		x;
	int		fd;

	fd = open("./text.txt", O_RDONLY);
	x = 1;
	line = NULL;
	printf("------------------------------------------------------\n");
	while (x > 0)
	{
		x = get_next_line(fd, &line);
		printf("[%d] line: %s\n", x, line);
		ft_strdel(&line);
		line = NULL;
		printf("-----------------------------------------------------\n");
	}
	close(fd);
	return (0);
}
