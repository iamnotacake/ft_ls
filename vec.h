/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:05:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 17:29:11 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_H
# define __VEC_H

# include <stdbool.h>

# define VEC_NTH(vec, index, type)		((type)((vec)->data[(index)]))
# define VEC_NTH_SET(vec, index, val)	((vec)->data[(index)] = (void *)(val))

typedef struct	s_vec
{
	void	**data;
	int		length;
	int		capacity;
}				t_vec;

void			vec_init(t_vec *vec);
void			vec_realloc(t_vec *vec, int need);
void			vec_free(t_vec *vec, bool free_elems);

void			vec_push(t_vec *vec, void *item);
void			*vec_pop(t_vec *vec);

void			vec_iter(t_vec *vec, void (*func)(void *));
void			vec_enumerate(t_vec *vec, void (*func)(int, void *));

void			vec_sort_qsort(t_vec *vec,
								int (*compare)(const void *, const void *));

#endif
