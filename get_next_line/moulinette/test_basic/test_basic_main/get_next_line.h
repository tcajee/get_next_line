/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:get_next_line/moulinette/test_basic/lnkambul/get_next_line.h
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:12:57 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/06 21:06:08 by lnkambul         ###   ########.fr       */
=======
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:22:24 by kseperep          #+#    #+#             */
/*   Updated: 2019/07/06 04:15:35 by tcajee           ###   ########.fr       */
>>>>>>> e8f0b29e219526aa57baba1a7b124dbee79a0908:get_next_line/get_next_line.h
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
<<<<<<< HEAD:get_next_line/moulinette/test_basic/lnkambul/get_next_line.h
# define BUFF_SIZE 32
#include <fcntl.h>
#include "libft/libft.h"

=======

# include <fcntl.h>
# include "libft/libft.h"
# include <sys/uio.h>

# define BUFF_SIZE 1024

>>>>>>> e8f0b29e219526aa57baba1a7b124dbee79a0908:get_next_line/get_next_line.h
int		get_next_line(const int fd, char **line);

#endif
