/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:51:11 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 18:01:02 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void			str_init(t_str *str)
{
	str->string = NULL;
	str->length = 0;
	str->capacity = 0;
}

void			str_realloc(t_str *str, int need)
{
	int			new_capacity;
	char		*new_string;

	need += need % ALLOC_CHUNK;
	new_capacity = str->capacity + need;
	new_string = (char *)malloc(new_capacity);
	if (str->length > 0)
	{
		MEMCPY(new_string, str->string, str->length);
		free(str->string);
	}
	str->string = new_string;
	str->capacity = new_capacity;
}

void			str_free(t_str *str)
{
	if (str->capacity)
	{
		free(str->string);
		str_init(str);
	}
}
