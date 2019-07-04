/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:17:44 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/02 15:15:24 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# elif defined(_WIN32)
#	define FOPEN_MAX // Windows
# elif defined(_WIN64)
#	define FOPEN_MAX // Windows
# elif defined(__CYGWIN__) && !defined(_WIN32)
# define FOPEN_MAX // Windows (Cygwin POSIX under Microsoft Window)
# elif defined(__ANDROID__)
# define FOPEN_MAX // Android (implies Linux, so it must come first)
# elif defined(__linux__)
# define FOPEN_MAX // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
# elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
# include <sys/param.h>
# elif defined(BSD)
# define FOPEN_MAX // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
# elif defined(__hpux)
# define FOPEN_MAX // HP-UX
# elif defined(_AIX)
# define FOPEN_MAX // IBM AIX
# elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
# define FOPEN_MAX "ios" // Apple iOS
# elif defined(__sun) && defined(__SVR4)
# define FOPEN_MAX // Oracle Solaris, Open Indiana
# else
# define FOPEN_MAX INT_MAX
# include "./libft/libft.h"

typedef struct	s_files
{
	char		*file[FOPEN_MAX];
	char		*line;
}				t_files;

int				get_next_line(const int fd, char **line);

#endif
