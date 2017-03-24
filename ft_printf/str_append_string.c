/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_append_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:08:34 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:00 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int				str_append_string(t_str *str, const char *string)
{
	int			len;

	len = STRLEN(string);
	if (str->length + len > str->capacity)
		str_realloc(str, len);
	MEMCPY(str->string + str->length, string, len);
	str->length += len;
	return (len);
}

int				str_append_string_n(t_str *str, const char *string, int n)
{
	if (str->length + n > str->capacity)
		str_realloc(str, n);
	MEMCPY(str->string + str->length, string, n);
	str->length += n;
	return (n);
}
