/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:20:03 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 17:24:29 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void			vec_iter(t_vec *vec, void (*func)(void *))
{
	int			i;

	i = 0;
	while (i < vec->length)
	{
		func(vec->data[i]);
		i++;
	}
}

void			vec_enumerate(t_vec *vec, void (*func)(int, void *))
{
	int			i;

	i = 0;
	while (i < vec->length)
	{
		func(i, vec->data[i]);
		i++;
	}
}
