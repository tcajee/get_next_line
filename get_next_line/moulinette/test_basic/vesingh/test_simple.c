/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2019/07/06 04:38:59 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"
#define FT_(x, y) if (x) return y;

int		test_simple( void )
{
printf("	----------		OPEN FILES		----------\n");

	int		fdin =	open("test1.in", O_RDONLY);
	/* printf("int	fdin	=	[%d]	=	open(test1.in, O_RDONLY);\n", fdin); */

	int		fdout =	open("test1.out", O_WRONLY|O_CREAT);
	/* printf("int	fdout	=	[%d]	=	open(testfd.out, O_WRONLY|O_CREAT);\n", fdout); */

	int		r00 = 0;
	/* printf("int	r00	=	[%d]	=	NULL;\n", r00); */

	char	*line = NULL;
	/* printf("char	*line	=	NULL;\n"); */

printf("	----------		ERROR CHECK FDIN	----------\n");

	/* printf("if\n	((fdin = [%d] = -1) || (fdout = [%d] = -1))\n	return (-1);\n", fdin, fdout); */
	if (fdin == -1 || fdout == -1)
	{
		perror("	ERROR");
	/* printf("---------------------------------------------------------------------\n"); */
	}
	FT_((fdin == -1 || fdout == -1), -1);

/* printf("	----------		DUP2			----------\n"); */

	/* int max = sysconf(_SC_OPEN_MAX); */
	/* printf("int max = [%d] = sysconf(_SC_OPEN_MAX);\n", max); */

	/* printf("OPEN_MAX = [%d]\n", OPEN_MAX); */
	/* fdin = dup2(fdin, 1023); */
	/* printf("fdin = [%d] = dup2(fdin, [%d]);\n", fdin, 1023); */

	/* fdin = dup2(fdin, _SC_OPEN_MAX); */
	/* printf("fdin = [%d] = dup2(fdin, [%d]);\n", fdin, _SC_OPEN_MAX); */

	/* printf("fcntl(old-filedes, F_DUPFD, new-filedes)\n"); */
	/* printf("fdin = [%d] = open(test1.in, O_RDONLY);\n", fdin); */
	/* fdin =	fcntl(fdin, F_DUPFD, max); */
	/* printf("fdin2 = [%d] = fctnl([%d], F_DUPFD, [%d]);\n", fdin, fdin, max); */

/* printf("	----------		ERROR CHECK FDIN	----------\n"); */

	/* printf("if\n	((fdin = [%d] = -1) || (fdout = [%d] = -1))\n	return (-1);\n", fdin, fdout); */
	if (fdin == -1 || fdout == -1)
	{
		perror("	ERROR");
	/* printf("---------------------------------------------------------------------\n"); */
	}
	FT_((fdin == -1 || fdout == -1), -1);

printf("	----------		CALL GNL		----------\n");

	/* printf("while\n	(r00 = [%d] = get_next_line(%d, %s)\n", r00, fdin, line); */
	while ((r00 = get_next_line(fdin, &line)) == 1){
		/* printf("	r00 = [%d] ; line = [%s]\n", r00, line); */
		write(fdout, line, strlen(line));
		write(fdout, "\n", 1);
		free(line);
	}

printf("	----------		CLOSE FILES		----------\n");

	close(fdin);
	/* printf("fdin = close(fdin)\n"); */
	close(fdout);
	/* printf("fdout = close(fdout)\n"); */

printf("	----------		CHMOD			----------\n");

	chmod("testfd.out", 0644);
	/* printf("chmod(testfd.out, 0644); // -rw-r--r--\n"); */

printf("	----------		SET FILE *		----------\n");

	FILE	*fpin = fopen("test1.in", "r+");
	/* printf("FILE	*fpin	= %p =	fopen(test1.in, r+);\n", fpin); */
	FILE	*fpout = fopen("testfd.out", "r+");
	/* printf("FILE	*fpout	= %p =	fopen(testfd.out, r+)\n", fpout); */

	if (!fpin || !fpout)
		perror("error:	");

printf("	----------		ERROR CHECK FPIN/OUT	----------\n");

/* printf("if\n	(!fpin == [%d] || !fpout == [%d])\n	return (0)\n", fdin, fdout); */
	FT_((!fpin || !fpout), -1)

printf("	----------		READ CHARS FROM FPS	----------\n");

	fdin = getc(fpin);
	/* printf("fdin	= {%c} = getc(fpin = %p);\n", fdin, fpin); */
	fdout = getc(fpout);
	/* printf("fdout	= {%c} = getc(fpout = %p);\n", fdout, fpout); */

printf("	----------		CHECK CHAR BY CHAR	----------\n");

	/* printf("while	((fdin != EOF) && (fdout != EOF) && (fdin == fdout))\n"); */
	/* printf("{%c} = {%c}\n", fdin, fdout); */
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		/* printf("fdin =	{%c} =	getc(fpin = %p);\n", fdin, fpin); */
		fdout = getc(fpout);
		/* printf("fdout =	{%c} =	getc(fpout = %p);\n", fdout, fpout); */
	}

printf("	----------		CHECK FOR MATCH		----------\n");

	if (fdin != fdout){
		/* printf("if\n	((fdin = {%c}) != (fdout = {%c})\n", fdin, fdout); */
		r00 = 1;
		/* printf("	r00 = [%d] = 1\n", r00); */
	}

printf("	----------		FINAL OUTPUT		----------\n");
	/* printf("r00	=	[%d]\n", r00); */
	if (r00 == 0) {
		printf("	test_fds_%d:	[ok]\n", BUFF_SIZE);
		return 1;
	}
	printf("test_fds_%d:	[ko]\n", BUFF_SIZE);
	return 0;
}
