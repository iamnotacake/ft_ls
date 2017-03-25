/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:27:15 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 17:53:06 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vec.h"

void			vec_sort_qsort(t_vec *vec,
								int (*compare)(const void *, const void *))
{
	if (vec->length >= 2)
		qsort(vec->data, vec->length, sizeof(void *), compare);
}
