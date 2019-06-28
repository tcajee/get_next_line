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

//---<char *find_new_line(char *BUFF)>-------------------------------------{{{
// fcntl(fd, F_GETFD)␣
static int	find_new_line(int fd, char **files)
{
	char	*temp;
	int		bytes;
	char	buffer[BUFF_SIZE + 1];

	if (files[fd] == NULL)
		files[fd] = ft_strnew(0);
	while (ft_strchr(files[fd], '\n') == NULL)
	{
		if ((bytes = read(fd, buffer, BUFF_SIZE)) == 0)
			break ;
		if (bytes < 0)
			return (-1);
		buffer[bytes] = '\0';
		temp = ft_strjoin(files[fd], buffer);
		ft_strdel(&files[fd]);
		files[fd] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	return (0);
}
//}}}

//---<int	get_next_line(const int fd, char **line)>------------------------{{{

int	get_next_line(const int fd, char **line)
{
	static char	*files[1024];
	char		*temp;
	char		*temp2;
	
	if (fd < 0 || !line || find_new_line(fd, files) < 0)
		return (-1);
	if (ft_strchr(files[fd], '\n') != NULL)
	{
		temp = ft_strdup(files[fd]);
		ft_strdel(&files[fd]);
		temp2 = ft_memset(ft_strchr(temp, '\n'), '\0', 1) + 1;
		*line = ft_strdup(temp);
		files[fd] = ft_strdup(temp2);
		ft_strdel(&temp);
	}
	else if (ft_strlen(files[fd]) > 0)
	{
		*line = ft_strdup(files[fd]);
		ft_strdel(&files[fd]);
	}
	else
		return (0);
	return (1);
}

//}}}

//---<int main(void)>--------------------------------------------------------{{{

int main(void)
{
	char	*line = NULL;
	FILE	*fd = fopen("./one_big_fat_line.txt", "r");

	if (!fd)
		return (-99);
	while (get_next_line(fileno(fd), &line) > 0)
		printf("line: %s\n", line);
	fclose(fd);
	return (0);
}

//}}}
