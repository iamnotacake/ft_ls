/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:53:45 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 14:46:39 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_print_list_callback(void *arg)
{
	t_fileinfo	*fi;

	fi = (t_fileinfo *)arg;
	ft_printf("%s", fi->fmt_perms);
	ft_printf("%*s", fi->fmt_nlinks_pad, fi->fmt_nlinks);
	ft_printf("%-*s", fi->fmt_owner_name_pad, fi->fmt_owner_name);
	ft_printf("%-*s", fi->fmt_owner_group_pad, fi->fmt_owner_group);
	ft_printf("%*s", fi->fmt_size_pad, fi->fmt_size);
	ft_printf("%s", fi->fmt_mtime);
	ft_printf("%s\n", fi->fmt_name);
}

static void		ls_print_list_prepare_callback(void *arg)
{
	t_fileinfo	*fi;

	fi = (t_fileinfo *)arg;
	fileinfo_format(fi);
}

static void		ls_print_list_prepare(t_list *list)
{
	vec_iter(&list->items, ls_print_list_prepare_callback);
	ls_print_list_prepare_nlinks_pad(list);
	ls_print_list_prepare_owner_name_pad(list);
	ls_print_list_prepare_owner_group_pad(list);
	ls_print_list_prepare_size_pad(list);
	ls_count_blocks(list);
}

void			ls_print_list(t_list *list)
{
	if (g_params['\n'])
		ft_printf("\n");
	ls_print_list_prepare(list);
	if (list->print_path)
		ft_printf("%s:\n", list->path);
	if (list->path[0] && g_params['l'])
		ft_printf("total %d\n", list->nblocks);
	vec_iter(&list->items, ls_print_list_callback);
	g_params['\n'] = true;
}
