/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/17 16:33:22 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			status;
	size_t		count;
	static char	*buffer;

	count = 0;
	buffer = *line;
	while (count < BUFF_SIZE)
	{
		if (*(buffer + count) != '\n')
			status = read(fd, buffer + count, 1);
		else if (*(buffer + count) == '\n')
			buffer += count;
		else if (status == -1)
			return (status);
		count++;
	}
	if (status > 0)
		return (1);
	return (status);
}
