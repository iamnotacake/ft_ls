/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:59:44 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 15:06:54 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include "ft_ls.h"

static void		ls_readdir(t_list *list)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*fi;
	char			fullname[1024];

	if ((dir = opendir(list->path)) == NULL)
	{
		perror("ft_ls");
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.' && !g_params['a'])
			continue ;
		fi = (t_fileinfo *)malloc(sizeof(t_fileinfo));
		__builtin_strcpy(fullname, list->path);
		__builtin_strcat(fullname, "/");
		__builtin_strcat(fullname, entry->d_name);
		fileinfo_get(fi, fullname, false);
		vec_push(&list->items, fi);
	}
	closedir(dir);
	ls_sort(&list->items);
}

static void		ls_recursive_callback(void *arg)
{
	// TODO
}

static void		ls(t_list *list)
{
	ls_print_list(list);
	if (g_params['R'])
	{

	}
}

void			ls_main_singles(t_fileinfo **fi, int count)
{
	int			i;
	t_list		list;

	list.print_path = false;
	vec_init(&list.items);
	i = 0;
	while (i < count)
		vec_push(&list.items, fi[i++]);
	ls(&list);
	vec_free(&list.items, false);
}

void			ls_main_dirs(t_fileinfo **fi, int count, bool x)
{
	int			i;
	t_list		list;

	i = 0;
	while (i < count)
	{
		__builtin_strcpy(list.path, fi[i]->name);
		list.print_path = count > 1 || x;
		vec_init(&list.items);
		ls_readdir(&list);
		ls(&list);
		vec_free(&list.items, true);
		i++;
	}
}
