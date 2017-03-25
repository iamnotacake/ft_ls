/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:09:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 19:55:27 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_pre_main_sort_callback(const void *a, const void *b)
{
	t_fileinfo	*fi1;
	t_fileinfo	*fi2;

	fi1 = *(t_fileinfo **)a;
	fi2 = *(t_fileinfo **)b;
	if ((S_ISDIR(fi1->stat.st_mode) && S_ISDIR(fi2->stat.st_mode)) ||
		(!S_ISDIR(fi1->stat.st_mode) && !S_ISDIR(fi2->stat.st_mode)))
		return (__builtin_strcmp(fi1->name, fi2->name));
	return (S_ISDIR(fi1->stat.st_mode) ? 1 : -1);
}

void			ls_pre_main(t_vec *vec)
{
	t_vec		items;
	t_fileinfo	*fi;
	int			i;

	ft_printf("Listing %d files/dirs\n", vec->length);
	vec_init(&items);
	i = 0;
	while (i < vec->length)
	{
		ft_printf("before sort: #%d: %s\n", i, vec->data[i]);
		fi = (t_fileinfo *)malloc(sizeof(t_fileinfo));
		fileinfo_get(fi, vec->data[i], true);
		vec_push(&items, fi);
		i++;
	}
	vec_sort_qsort(&items, ls_pre_main_sort_callback);
	i = 0;
	while (i < items.length)
	{
		ft_printf("after sort:  #%d: %s\n",
					i, VEC_NTH(&items, i, t_fileinfo *)->name);
		i++;
	}
	vec_free(&items, true);
}
