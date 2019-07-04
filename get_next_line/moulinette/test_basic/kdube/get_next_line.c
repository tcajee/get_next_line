/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdube <marvin@42.FR>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/02 15:31:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    get_next_line(const int fd, char **line)
{
    static char    *c[2147483647];
    char        buffer[BUFF_SIZE + 1];
    char         *t;
    ssize_t        b;
	int            endl;

	b = 0;
    if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
        return (-1);
    while (!ft_strchr(c[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        buffer[b] = '\0';
        t = c[fd];
        c[fd] = ft_strjoin(c[fd], buffer);
        ft_strdel(&t);
    }
    if (b == -1 || !*(t = c[fd]))
        return (b == -1 ? -1 : 0);
    if ((endl = (ft_strchr(c[fd], '\n') > 0)))
        *line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
    else
        *line = ft_strdup(c[fd]);
    c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
            (size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
    ft_strdel(&t);
    return (!(!c[fd] && !ft_strlen(*line)));
}
