/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overheads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:11:05 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/10 13:50:53 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/resource.h>
#include <sys/time.h>


#define FT_MALLOC x + y + 1
#define FT_BZERO x + y + 1
#define FT_COPY x
#define FT_CAT y
#define FT_LEN1 x + y
#define FT_LEN2 BUFF_SIZE
#define FT_OVER xy + 2x2y + xy = 4x4y

static int	copy_next_line(t_files *files, int fd, char **line, t_over *over)
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

static int	find_next_line(t_files *files, int fd, char **line, t_over *over)
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
		return (copy_next_line(files, fd, line, over));
	else if (ft_strlen(files->file[fd]) > 0)
	{
		FT_(!(*line = ft_strdup(files->file[fd])), -1);
		ft_strdel(&files->file[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line, t_over *over)
{
	static t_files files;

	FT_((!line || read(fd, NULL, 0) == -1), -1);
	if (!files.file[fd])
		files.file[fd] = ft_strnew(0);
	
	time = getrusage(who, &usage);


	return (find_next_line(&files, fd, line, over));
}

int	main(void)
{
	static t_over over;
	char	*line;
	long	bytes;
	int		fd;
	int		total;

	line = NULL;
	bytes = 1;
	fd = open("./bible.txt", O_RDONLY);
	/* fd = open("./test.txt", O_RDONLY); */
	total = 0;
printf("-------------------CALL GNL-----------------------\n");


while (bytes > 0)
	{
/* printf("--------------------------------------------\n"); */
		bytes = get_next_line(fd, &line, &over);
		/* printf("[%d] line: %s\n", bytes, line); */
		ft_strdel(&line);
		line = NULL;
		total++;
/* printf("--------------------------------------------\n"); */
	}



printf("BUFF_SIZE is set to [%ld]\n", BUFF_SIZE);
printf("Total chars in file [4351186]\n");
printf("Total lines printed [%d]\n", total);
	close(fd);
	return (0);
}
