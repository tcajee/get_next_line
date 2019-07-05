/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:37:39 by uisrael           #+#    #+#             */
/*   Updated: 2019/07/02 17:40:05 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*s[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		b;
	int			endl;

	if (fd < 0 || (!s[fd] && !(s[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		temp = s[fd];
		s[fd] = ft_strjoin(s[fd], buffer);
		ft_strdel(&temp);
	}
	if (b == -1 || !*(temp = s[fd]))
		return (b == -1 ? -1 : 0);
	if ((endl = (ft_strchr(s[fd], '\n') > 0)))
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	else
		*line = ft_strdup(s[fd]);
	s[fd] = ft_strsub(s[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(s[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&temp);
	return (!(!s[fd] && !ft_strlen(*line)));
}
