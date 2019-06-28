/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:42:26 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/07 16:21:38 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	else
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
		}
		else
		{
			new->content = ft_memcpy(ft_memalloc(content_size), content, \
					content_size);
			new->content_size = content_size;
			new->next = NULL;
		}
	}
	return (new);
}
