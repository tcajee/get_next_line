/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchewa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:13:47 by tchewa            #+#    #+#             */
/*   Updated: 2019/07/15 14:42:58 by tchewa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>

# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);

#endif
