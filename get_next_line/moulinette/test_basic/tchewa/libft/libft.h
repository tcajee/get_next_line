/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchewa <tchewa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 09:31:26 by tchewa            #+#    #+#             */
/*   Updated: 2019/07/09 14:56:12 by tchewa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_strcat(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *s, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
