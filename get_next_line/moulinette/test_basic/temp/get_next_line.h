/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:17:44 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/03 17:52:44 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 100

typedef struct	s_bmark
{
	char			*red;
	int				fd;
	struct s_bmark	*next;
}				t_bmark;

int				get_next_line(const int fd, char **line);

#endif
