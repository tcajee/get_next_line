/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:29:40 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/24 18:12:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//---<subject>---------------------------------------------------------------{{{

// The first parameter is the file descriptor that will be used to read.
// The second parameter is the address of a pointer to a character that will be used to save the line read from the file descriptor.

// The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.

// Your function get_next_line must return its result without ’\n’.

// Calling your function get_next_line in a loop will then allow you to read the texavailable on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

// Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.

// We consider that get_next_line has an undefined behavior if, between two calls, the same file descriptor designs two distinct files although the reading from the first file was not completed.

// We consider also that a call to lseek(2) will never take place between two calls of the function get_next_line on the same file descriptor.

// Finally we consider that get_next_line has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.
//}}}

//---<char *ft_next_newline(char *BUFF)>-------------------------------------{{{

size_t	ft_next_newline(char *buff)
{
	size_t len;

	len = 0;
	if (buff)
	{
		while (buff[len] != '\n')
			len++;
	}
	return (len);
}

//}}}

//---<void ft_buffprint(t_buffer *head)>-----------------------------------{{{
void ft_buffprint(t_buffer *head)
{
	int node;
	t_buffer *temp;

	node = 0;
	temp = head;
	while(temp)
	{
		printf("---------------------------------------------------------\n");
		printf("node[%d]: address:	%p	\n", node, temp);
		printf("node[%d]->buffer:	%s	\n", node, temp->buffer);
		printf("node[%d]->line:		%s	\n", node, temp->line);
		printf("node[%d]->buff_size	%zu	\n", node, temp->buff_size);
		printf("node[%d]->fd		%d	\n", node, temp->fd);
		printf("node[%d]->next		%p	\n", node, temp->next);
		printf("---------------------------------------------------------\n");
		temp = temp->next;
		node++;
	}
	printf("total nodes printed = %d: \n", node);
	printf("---------------------------------------------------------\n");
}

//}}}

//---<t_list *ft_buffnew(const int fd, static char **buffer)>----------{{{

t_buffer	*ft_buffnew(const int fd, char *buffer)
{
	t_buffer	*node;

	if (!(node = (t_buffer *)malloc(sizeof(t_buffer))))
		return (NULL);
	node->buffer = ft_memcpy(ft_strnew(BUFF_SIZE), buffer, BUFF_SIZE);
	node->line = ft_strncpy(ft_strnew(ft_next_newline(buffer)), buffer, \
			ft_next_newline(buffer));
	node->buff_size = BUFF_SIZE;
	node->fd = fd;
	node->next = NULL;
	return (node);
}

//}}}

//---<t_list *ft_buffadd(const int fd, static char **buffer)>----------{{{

/* t_buffer	*ft_buffadd(t_buffer *new) */
/* { */
/* 	t_buffer	*node; */
/* 	if (!(node = (t_buffer *)malloc(sizeof(t_buffer)))) */
/* 		return (NULL); */
/* 	node->buffer = new->buffer; */
/* 	node->line = new->line; */
/* 	node->buff_size = new->buff_size; */
/* 	node->fd = new->fd; */
/* 	node->next = NULL; */
/* 	return (node); */
/* } */

//}}}

//---<int	get_next_line(const int fd, char **line)>------------------------{{{

int	get_next_line(const int fd, char **line)
{
	int				status;
	char			*buffer;
	static t_buffer	*head = NULL;
	t_buffer		*cursor;

	if (fd < 0 || !line)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	printf("-----------------------------------------------------------------\n");
	while ((status = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!head)
			head = ft_buffnew(fd, buffer);
		cursor = head;
		while (cursor->fd != fd && cursor)
		{
			cursor = cursor->next;

		}

		*line = cursor->line;
		printf("line: %s\n", *line);
	}
	printf("-----------------------------------------------------------------\n");
	ft_buffprint(head);
	return (status);
}

//}}}

//---<int main(void)>--------------------------------------------------------{{{

int main(void)
{
	char	*line = NULL;
	FILE	*fd = fopen("./test.txt", "r");

	if (!fd)
		return (-99);
	printf("GNL: %d\n", get_next_line(fileno(fd), &line));
	printf("--------------------------------------------------------------------\n");
	printf("line: %s\n", line);
	printf("--------------------------------------------------------------------\n");
	fclose(fd);
	return (0);
}

//}}}
