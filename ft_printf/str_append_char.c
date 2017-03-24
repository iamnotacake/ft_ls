/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_append_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:02:15 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:59 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int				str_append_char(t_str *str, char chr)
{
	if (str->length + 1 > str->capacity)
		str_realloc(str, 1);
	str->string[str->length++] = chr;
	return (1);
}

int				str_append_char_n(t_str *str, char chr, int count)
{
	int			ret;

	if (count <= 0)
		return (0);
	ret = count;
	if (str->length + count > str->capacity)
		str_realloc(str, count);
	while (count--)
		str->string[str->length++] = chr;
	return (ret);
}
