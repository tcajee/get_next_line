/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:29:02 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/08 13:04:25 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	define BUFF_SIZE 1
#	include <stdlib.h>
#	include <stdio.h>
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <sys/uio.h>
#	include <unistd.h>
#	include <fcntl.h>
#	include "libft/libft.h"

int		get_next_line(const int fd, char **line);
#endif
