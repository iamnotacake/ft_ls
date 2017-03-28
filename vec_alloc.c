/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:07:41 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/28 16:44:21 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vec.h"

void			vec_init(t_vec *vec)
{
	vec->data = NULL;
	vec->length = 0;
	vec->capacity = 0;
}

void			vec_realloc(t_vec *vec, int need)
{
	int			new_capacity;
	void		*new_data;

	need += need % 64;
	new_capacity = vec->capacity + need;
	new_data = (void **)malloc(sizeof(void *) * new_capacity);
	if (vec->length > 0)
		__builtin_memcpy(new_data, vec->data, sizeof(void *) * vec->length);
	if (vec->capacity > 0)
		free(vec->data);
	vec->data = new_data;
	vec->capacity = new_capacity;
}

void			vec_free(t_vec *vec, bool free_elems)
{
	int			i;

	if (vec->length > 0 && free_elems)
	{
		i = 0;
		while (i < vec->length)
			free(vec->data[i++]);
	}
	if (vec->capacity > 0)
		free(vec->data);
	vec_init(vec);
}
