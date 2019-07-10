/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/10 11:24:33 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int	copy_next_line(t_files *files, int fd, char **line)
{
	char	*split;
	int		index;

	split = files->file[fd];
	index = ft_strchr(split, '\n') - split;
	FT_(!(*line = ft_strsub(split, 0, index)), -1);
	FT_(!(files->file[fd] =
		ft_strsub(split, index + 1, ft_strlen(split) - index)), -1);
	ft_strdel(&split);
	return (1);
}

static int	find_next_line(t_files *files, int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*stage;
	long	bytes;

	while (ft_strchr(files->file[fd], '\n') == NULL)
	{
		FT_((bytes = read(fd, buffer, BUFF_SIZE)) == 0, 0);
		FT_(bytes < 0, -1);
		buffer[bytes] = '\0';
		FT_(!(stage = ft_strjoin(files->file[fd], buffer)), -1);
		ft_strdel(&files->file[fd]);
		files->file[fd] = stage;
	}
	if (ft_strchr(files->file[fd], '\n'))
		return (copy_next_line(files, fd, line));
	else if (ft_strlen(files->file[fd]) > 0)
	{
		FT_(!(*line = ft_strdup(files->file[fd])), -1);
		ft_strdel(&files->file[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_files files;

	FT_((!line || read(fd, NULL, 0) == -1), -1);
	if (!files.file[fd])
		files.file[fd] = ft_strnew(0);
	return (find_next_line(&files, fd, line));
}


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
		ft_strdel(&line);
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
