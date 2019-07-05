/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/03 07:38:59 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	assign(char **string, char **temp)
{
	char	*stage;
/* printf("------------ASSIGN---------------------\n"); */

	stage = ft_strdup(*string);
	ft_memset(ft_strchr(stage, '\n'), '\0', 1);
	*temp = ft_strdup(stage);
	ft_strdel(string);
	*string = ft_strdup((ft_strchr(stage, '\0')) + 1);
	ft_strdel(&stage);
	return (1);
}

static int	create(int fd, char **string)
{
	char		buff[BUFF_SIZE + 1];
	char		*stage;
	int			red;
	
	while (!ft_strchr(*string, '\n'))
	{
/* printf("--------------------CREATE------------------\n"); */
		if ((red = read(fd, buff, BUFF_SIZE)) == 0)
			return (0);
		if (red < 0)
			return (-1);
		buff[red] = '\0';
		stage = ft_strjoin(*string, buff);
		ft_strdel(string);
		*string = ft_strdup(stage);
		ft_strdel(&stage);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*string = NULL;
	char	*temp;

	if (!string)
		string = ft_strnew(0);
/* printf("--------------------INIT------------------\n"); */
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (create(fd, &string) < 0)
		return (-1);
	if (ft_strchr(string, '\n'))
	{
		assign(&string, &temp);
		*line = ft_strdup(temp);
		ft_strdel(&temp);
	}
	else if (ft_strlen(string) > 0)
	{
		*line = ft_strdup(string);
	}
	else
		return (0);
	return (1);
}
