/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:13:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 15:12:59 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_sort_by_name_callback(const void *a, const void *b)
{
	const char	*x;
	const char	*y;

	x = (*(t_fileinfo **)a)->name;
	y = (*(t_fileinfo **)b)->name;
	if (g_params['r'])
		return (__builtin_strcmp(y, x));
	else
		return (__builtin_strcmp(x, y));
}

int				ls_sort_by_mtime_callback(const void *a, const void *b)
{
	time_t	x;
	time_t	y;

	x = (*(t_fileinfo **)a)->stat.st_mtime;
	y = (*(t_fileinfo **)b)->stat.st_mtime;
	if (g_params['r'])
		return (x - y);
	else
		return (y - x);
}

void			ls_sort(t_vec *vec)
{
	if (g_params['t'])
		vec_sort_qsort(vec, ls_sort_by_mtime_callback);
	else
		vec_sort_qsort(vec, ls_sort_by_name_callback);
}
