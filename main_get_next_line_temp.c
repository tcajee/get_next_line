/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:29:40 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/25 18:32:30 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

//---<char *find_new_line(char *BUFF)>-------------------------------------{{{
// fcntl(fd, F_GETFD)␣

/* static int	find_new_line(int fd, char **files) */
/* { */
/* 	char	*temp; */
/* 	int		bytes; */
/* 	char	buffer[BUFF_SIZE + 1]; */
/* 	if (files[fd] == NULL) */
/* 		files[fd] = ft_strnew(0); */
/* 	while (ft_strchr(files[fd], '\n') == NULL) */
/* 	{ */
/* 		if ((bytes = read(fd, buffer, BUFF_SIZE)) == 0) */
/* 			break ; */
/* 		if (bytes < 0) */
/* 			return (-1); */
/* 		buffer[bytes] = '\0'; */
/* 		temp = ft_strjoin(files[fd], buffer); */
/* 		ft_strdel(&files[fd]); */
/* 		files[fd] = ft_strdup(temp); */
/* 		ft_strdel(&temp); */
/* 	} */
/* 	return (0); */
/* } */

//}}}

//---<int	get_next_line(const int fd, char **line)>------------------------{{{

/* int	get_next_line(const int fd, char **line) */
/* { */
/* 	static char	*files[1024]; */
/* 	char		*temp; */
/* 	char		*temp2; */
/* 	if (fd < 0 || !line || find_new_line(fd, files) < 0) */
/* 		return (-1); */
/* 	if (ft_strchr(files[fd], '\n') != NULL) */
/* 	{ */
/* 		temp = ft_strdup(files[fd]); */
/* 		ft_strdel(&files[fd]); */
/* 		temp2 = ft_memset(ft_strchr(temp, '\n'), '\0', 1) + 1; */
/* 		*line = ft_strdup(temp); */
/* 		files[fd] = ft_strdup(temp2); */
/* 		ft_strdel(&temp); */
/* 	} */
/* 	else if (ft_strlen(files[fd]) > 0) */
/* 	{ */
/* 		*line = ft_strdup(files[fd]); */
/* 		ft_strdel(&files[fd]); */
/* 	} */
/* 	else */
/* 		return (0); */
/* 	return (1); */
/* } */

//}}}

//---<>---------------------------------------------------------------{{{


static int	find_new_line(t_files *files, int fd, char **file)
{
	int	bytes;
	char	*buffer;

	if (!file[fd])
		file[fd] = ft_strnew(0);
	while (ft_strchr(file[fd], '\n') == NULL)
	{
		if (!(buffer = (char *)malloc(sizeof(char) *BUFF_SIZE + 1)))
			return (-1);
		if ((bytes = read(fd, buffer, BUFF_SIZE)) == 0)
			break ;
		if (bytes < 0)
			return (-1);
		files->stage = ft_strjoin(file[fd],\
				ft_memset(buffer + bytes, '\0', 1) - bytes);
		ft_strdel(&file[fd]);
		file[fd] = ft_strdup(files->stage);
		ft_strdel(&files->stage);
		ft_strdel(&buffer);
	}
	return (0);
}


//}}}

//---<>---------------------------------------------------------------{{{

int			get_next_line(const int fd, char **line)
{
	static t_files files;

	if (fd < 0 || !line || find_new_line(&files, fd, files.file) < 0)
		return (-1);
	if (ft_strchr(files.file[fd], '\n') != NULL)
	{
		files.stage = ft_strdup(files.file[fd]);
		*line = ft_strdup(ft_memset(ft_strchr(\
						files.stage, '\n'), '\0', 1) - ft_strlen(files.stage));
		ft_strdel(&files.file[fd]);
		files.file[fd] = ft_strdup(ft_strchr(files.stage, '\0') + 1);
		ft_strdel(&files.stage);
	}
	else if (files.file[fd][0])
	{
		*line = ft_strdup(files.file[fd]);
		ft_strdel(&files.file[fd]);
	}
	else
	{
		ft_strdel(line);
		ft_strdel(&files.file[fd]);
		return (1);
	}
		return (0);
}

//}}}

//---<int main(void)>--------------------------------------------------------{{{

int main(void)
{
	char	*line = NULL;
	int fd = open("./test.txt", O_RDONLY);

	if (!fd)
		return (-99);
	if (get_next_line(fd, &line) > 0)
		printf("line: %s\n", line);
	ft_strdel(&line);
	close(fd);
	
	return (0);
}

//}}}

//---<>---------------------------------------------------------------{{{

/* int main(void) */
/* { */
/* 	char *line = NULL; */
/* 	while (get_next_line(open("./test.txt", O_RDONLY), &line)) */
/* 		printf("%s\n", line); */
/* 	while(1) */
/* 	return (0); */
/* } */

//}}}
