/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 08:28:55 by vesingh           #+#    #+#             */
/*   Updated: 2019/07/08 16:38:46 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/* static int ft_storetoline(char **store, char **line) */
/* { */
/* 	int len; */
/* 	char	*temp; */
/* 	if (ft_strchr(*store, '\n')) */
/* 	{ */
/* 		len = ft_strchr(*store, '\n') - *store; */
/* 		*line = ft_strsub(*store, 0, len); */
/* 		temp = ft_strchr(*store, '\n') + 1; */
/* 		temp = ft_strdup(temp); */
/* 		ft_strdel(store); */
/* 		*store = ft_strdupdel(&temp); */
/* 		if (*store[0] == '\0') */
/* 			ft_strdel(store); */
/* 	} */
/* 	else if (ft_strchr(*store, '\0')) */
/* 		*line = ft_strdupdel(store); */
/* 	return (1); */
/* } */

static int	ft_storetoline(char **store, char **line)
{
	int		len;
	char	*temp;
	if (ft_strchr(*store, '\n'))
	{
		temp = *store;
		len = ft_strchr(temp, '\n') - temp;
		*line = ft_strsub(temp, 0, len);
		*store = ft_strsub(temp, len + 1, ft_strlen(temp) - len);
		ft_strdel(&temp);
	}
	else if (*store[0] != '\0')
		*line = ft_strdupdel(store);
	return (1);
}

static int	ft_reader(char **store, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		n;
	while (!ft_strchr(*store, '\n'))
	{
		if ((n = read(fd, buff, BUFF_SIZE)) == 0)
			return (0);
		buff[n] = '\0';
		*store = ft_strjoinfree(*store, buff);
	}
	return (n);
}

static int ft_reader(char **store, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		n;
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		*store = ft_strjoinfree(*store, buff);
		if (ft_strchr(*store, '\n'))
			break ;
	}
	return (n);
}

int			get_next_line(const int fd, char **line)
{
	static char	*store[1024];
	int			n;

	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!store[fd])
		store[fd] = ft_strnew(0);
	if ((n = ft_reader(&store[fd], fd)) < 0)
		return (-1);
	else if (n == 0 && (store[fd] == NULL || store[fd][0] == '\0'))
		return (0);
	else
		return (ft_storetoline(&store[fd], line));
	return (0);
}
