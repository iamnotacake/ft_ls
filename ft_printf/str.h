/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:49:34 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:39:49 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STR_H
# define __STR_H

# include <stdlib.h>

# define STRNCMP(a, b, n) __builtin_strncmp(a, b, n)
# define STRCPY(a, b) __builtin_strcpy(a, b)
# define MEMCPY(a, b, n) __builtin_memcpy(a, b, n)
# define BZERO(a, n) __builtin_bzero(a, n)
# define STRLEN(a) __builtin_strlen(a)
# define STRCMP(a, b) __builtin_strcmp(a, b)

# define ALLOC_CHUNK 64

typedef struct	s_str
{
	char	*string;
	int		length;
	int		capacity;
}				t_str;

void			str_init(t_str *str);
void			str_realloc(t_str *str, int need);
void			str_free(t_str *str);

int				str_append_char(t_str *str, char chr);
int				str_append_char_n(t_str *str, char chr, int count);

int				str_append_string(t_str *str, const char *string);
int				str_append_string_n(t_str *str, const char *string, int n);

#endif
