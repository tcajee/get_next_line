/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saburadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:03:29 by saburadi          #+#    #+#             */
/*   Updated: 2018/08/20 17:34:45 by saburadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unixlib.h"

/*
** Note; this is a modified version of GNL (borrowed from Marco and called v4.0)
*/

static void		buffer_clean(char *buffer)
{
	int			i;
	int			j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		j = 0;
		while (buffer[i] && i > j)
		{
			buffer[j++] = buffer[i++];
		}
		buffer[j] = '\0';
	}
	else if (buffer[i] == '\0')
		ft_memset(buffer, 0, BUFF_SIZE + 1);
}

static int		newline_check(t_line *t, char *line[])
{
	char		*tmp;

	if (t->buffer[t->i] == '\n')
	{
		tmp = ft_strnjoin(*line, t->buffer, t->i);
		ft_strdel(line);
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		buffer_clean(t->buffer);
		t->i = 0;
		return (1);
	}
	return (0);
}

static void		copy_to_line(t_line *t, char *line[])
{
	char		*tmp;

	tmp = ft_strnjoin(*line, t->buffer, t->i + 1);
	ft_strdel(line);
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static int		return_check(int i, char *line)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
	{
		return (1);
	}
	else if (i == 0 && *line)
	{
		return (1);
	}
	else if (line != NULL)
		ft_strdel(&line);
	return (0);
}

int				get_next_line(const int fd, char *line[])
{
	static		t_line t;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == NULL)
		return (-1);
	if (t.buffer[t.i])
	{
		while (t.buffer[t.i] && t.buffer[t.i] != '\n')
			t.i++;
		if (newline_check(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	while ((t.r = read(fd, t.buffer, BUFF_SIZE)) > 0)
	{
		t.buffer[t.r] = '\0';
		t.i = 0;
		while (t.buffer[t.i] && t.buffer[t.i] != '\n')
			t.i++;
		if (newline_check(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	return (return_check(t.r, *line));
}