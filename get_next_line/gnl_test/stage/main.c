/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:29:40 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/10 09:58:42 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		x;
	int		fd;
	int		total;

	line = NULL;
	x = 1;
	fd = open("./bible.txt", O_RDONLY);
	/* fd = open("./test.txt", O_RDONLY); */
	total = 0;
printf("--------------------------------------------\n");
	while (x > 0)
	{
printf("--------------------------------------------\n");
		x = get_next_line(fd, &line);
		printf("[%d] line: %s\n", x, line);
		free(line);
		line = NULL;
		total++;
printf("--------------------------------------------\n");
	}
printf("BUFF_SIZE is set to [%d]\n", BUFF_SIZE);
printf("Total chars in file [4351186]\n");
printf("Total lines printed [%d]\n", total);
	
	close(fd);
	return (0);
}
