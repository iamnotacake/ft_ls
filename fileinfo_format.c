/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:18:23 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 15:26:37 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format(t_fileinfo *fi)
{
	if (g_params['l'])
	{
		fileinfo_format_perms(fi);
		fileinfo_format_nlinks(fi);
		fileinfo_format_owner_name(fi);
		fileinfo_format_owner_group(fi);
		fileinfo_format_size(fi);
		fileinfo_format_mtime(fi);
	}
	fileinfo_format_name(fi);
}
