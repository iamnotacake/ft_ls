/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_prepare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:39:33 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/26 18:53:59 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void			ls_print_list_prepare_nlinks_pad(t_list *list)
{
	int			i;
	int			padding;

	padding = 0;
	i = -1;
	while (++i < list->items.length)
		padding = ft_max(padding,
					strlen(VEC_NTH(&list->items, i, t_fileinfo *)->fmt_nlinks));
	i = -1;
	while (++i < list->items.length)
		VEC_NTH(&list->items, i, t_fileinfo *)->fmt_nlinks_pad = padding;
}

void			ls_print_list_prepare_owner_name_pad(t_list *list)
{
	int			i;
	int			padding;

	padding = 0;
	i = -1;
	while (++i < list->items.length)
		padding = ft_max(padding,
			strlen(VEC_NTH(&list->items, i, t_fileinfo *)->fmt_owner_name));
	i = -1;
	while (++i < list->items.length)
		VEC_NTH(&list->items, i, t_fileinfo *)->fmt_owner_name_pad = padding;
}

void			ls_print_list_prepare_owner_group_pad(t_list *list)
{
	int			i;
	int			padding;

	padding = 0;
	i = -1;
	while (++i < list->items.length)
		padding = ft_max(padding,
			strlen(VEC_NTH(&list->items, i, t_fileinfo *)->fmt_owner_group));
	i = -1;
	while (++i < list->items.length)
		VEC_NTH(&list->items, i, t_fileinfo *)->fmt_owner_group_pad = padding;
}
