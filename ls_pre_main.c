/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:09:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/26 19:41:59 by alischyn         ###   ########.fr       */
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

void			ls_count_blocks(t_list *list)
{
	int			i;
	int			size;

	list->nblocks = 0;
	i = -1;
	while (++i < list->items.length)
	{
		size = VEC_NTH(&list->items, i, t_fileinfo *)->stat.st_size;
		list->nblocks += size / 4096 + ((size % 4096) ? 1 : 0);
		/* ft_printf("% 4d => %d\n", size, size / 4096 + ((size % 4096) ? 1 : 0)); */
	}
}

static void		ls_pre_main_2(t_fileinfo **fi, int total)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < total && !S_ISDIR(fi[i]->stat.st_mode))
	{
		i++;
		count++;
	}
	if (count > 0)
		ls_main_singles(&fi[0], count);
	count = 0;
	while (i < total && S_ISDIR(fi[i]->stat.st_mode))
	{
		i++;
		count++;
	}
	if (count > 0)
		ls_main_dirs(&fi[i - count], count, count != total);
}

void			ls_pre_main(t_vec *vec)
{
	t_vec		items;
	t_fileinfo	*fi;
	int			i;

	vec_init(&items);
	i = 0;
	while (i < vec->length)
	{
		fi = (t_fileinfo *)malloc(sizeof(t_fileinfo));
		fileinfo_get(fi, vec->data[i], true);
		vec_push(&items, fi);
		i++;
	}
	vec_sort_qsort(&items, ls_pre_main_sort_callback);
	ls_pre_main_2((t_fileinfo **)items.data, items.length);
	vec_free(&items, true);
}
