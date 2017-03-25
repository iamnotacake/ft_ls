/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:43:21 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 15:24:16 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_name(t_fileinfo *fi)
{
	__builtin_strcpy(fi->fmt_name, fi->name);
	if (g_params['l'] && S_ISLNK(fi->stat.st_mode))
	{
		__builtin_strcat(fi->fmt_name, " -> ");
		__builtin_strcat(fi->fmt_name, fi->lnk_dest);
	}
}
