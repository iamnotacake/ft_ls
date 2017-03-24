/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:47 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 18:43:23 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool			fileinfo_get(t_fileinfo *fi, const char *filename)
{
	__builtin_bzero(fi, sizeof(t_fileinfo));
	if (lstat(filename, &fi->stat) == -1)
		return (false);
	if (g_params['l'])
		listxattr(filename, fi->xattr, sizeof(fi->xattr), XATTR_NOFOLLOW);
	if (g_params['l'] && (fi->pwd = getpwuid(fi->stat.st_uid)) == NULL)
		return (false);
	if (g_params['l'] && (fi->grp = getgrgid(fi->stat.st_gid)) == NULL)
		return (false);
	return (true);
}
