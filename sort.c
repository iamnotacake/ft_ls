/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:13:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 16:11:51 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_sort_by_name_callback(const void *a, const void *b)
{
	t_fileinfo	*fi1;
	t_fileinfo	*fi2;

	fi1 = (*(t_fileinfo **)a);
	fi2 = (*(t_fileinfo **)b);
	if (g_params['r'])
		return (__builtin_strcmp(fi2->name, fi1->name));
	else
		return (__builtin_strcmp(fi1->name, fi2->name));
}

int				ls_sort_by_mtime_callback(const void *a, const void *b)
{
	t_fileinfo	*fi1;
	t_fileinfo	*fi2;
	time_t		x;
	time_t		y;
	long		time_diff;

	fi1 = (*(t_fileinfo **)a);
	fi2 = (*(t_fileinfo **)b);
	x = fi1->stat.st_mtime;
	y = fi2->stat.st_mtime;
	time_diff = g_params['r'] ? x - y : y - x;
	if (time_diff < 0)
		return (-1);
	if (time_diff > 0)
		return (1);
	return (__builtin_strcmp(fi1->name, fi2->name));
}

void			ls_sort(t_vec *vec)
{
	if (g_params['t'])
		vec_sort_qsort(vec, ls_sort_by_mtime_callback);
	else
		vec_sort_qsort(vec, ls_sort_by_name_callback);
}
