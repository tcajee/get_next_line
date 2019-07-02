/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:17:44 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/30 17:10:27 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64
# include "./libft/libft.h"

typedef struct	s_files
{
	char		*file[1024];
	char		*stage;
	char		*buffer;
	char		*line;
	int			bytes;
}				t_files;

int				get_next_line(const int fd, char **line);

#endif
