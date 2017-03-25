/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:23:23 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 16:28:50 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vec.h"

void			vec_push(t_vec *vec, void *item)
{
	if (vec->length == vec->capacity)
		vec_realloc(vec, 1);
	vec->data[vec->length++] = item;
}

void			*vec_pop(t_vec *vec)
{
	if (vec->length > 0)
		return (vec->data[--vec->length]);
	return (NULL);
}
