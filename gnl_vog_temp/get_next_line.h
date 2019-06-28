/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:17:44 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 18:24:08 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "./libft/libft.h"

typedef struct	s_files
{
	// Array of [1024] pointers to strings  file indexes [0 to 1024]
	char		*file[1024];
	// Temporary string to store the result of read(fd, files->buffer, BUFF_SIZE + 1)
	char		*buffer;
	// Temporary string to store the value of static t_files->file[fd]
	char		*stage;
	// Temporary string to store result for paramater char **line
	char		*line;
}				t_files;

int				get_next_line(const int fd, char **line);

/* \+ This is the error check macro: FT_(x, y) if (x) return y; <------------------------------------------\ */
/* |																										| */
/* |				\* store	join															| */
/* |				|			|			|																| */
/* |				| 			|			|													| */
/* |				|			|			|															| */
/* v				v			v			v														v */ 
/* FT_(!(files->stage = ft_strjoin(files->file[fd],ft_memset((files->buffer + bytes), '\0', 1) - bytes)), -1); */


#endif
