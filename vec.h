/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:05:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 16:24:50 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_H
# define __VEC_H

typedef struct	s_vec
{
	void	**data;
	int		length;
	int		capacity;
}				t_vec;

void			vec_init(t_vec *vec);
void			vec_realloc(t_vec *vec, int need);
void			vec_free(t_vec *vec);

#endif
