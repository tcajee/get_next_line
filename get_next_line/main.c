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
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		x;
	int		fd;
	int		total;

	line = NULL;
	x = 1;
	fd = open("./bible.txt", O_RDONLY);
	total = 0;
printf("--------------------------------------------\n");
	while (x > 0)
	{
printf("--------------------------------------------\n");
		x = get_next_line(fd, &line);
		printf("[%d] line: %s\n", x, line);
		ft_strdel(&line);
		total++;
printf("--------------------------------------------\n");
	}
printf("BUFF_SIZE is set to [%d]\n", BUFF_SIZE);
printf("Total chars in file [4351186]\n");
printf("Total lines printed [%d]\n", total);
	
	close(fd);
	return (0);
}
