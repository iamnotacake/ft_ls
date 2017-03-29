/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:47 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 14:41:42 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*fullname_to_filename(const char *fullname)
{
	static char	filename[512];
	const char	*tmp;

	while ((tmp = __builtin_strchr(fullname, '/')) != NULL)
		fullname = tmp + 1;
	__builtin_strcpy(filename, fullname);
	return (filename);
}

bool			fileinfo_get(t_fileinfo *fi, const char *filename, bool single)
{
	__builtin_bzero(fi, sizeof(t_fileinfo));
	__builtin_strcpy(fi->name,
						single ? filename : fullname_to_filename(filename));
	if (lstat(filename, &fi->stat) == -1)
		return (false);
	if (g_params['l'])
		readlink(filename, fi->lnk_dest, sizeof(fi->lnk_dest) - 1);
	if (g_params['l'])
		listxattr(filename, fi->xattr, sizeof(fi->xattr), XATTR_NOFOLLOW);
	if (g_params['l'] && (fi->pwd = getpwuid(fi->stat.st_uid)) == NULL)
		return (false);
	if (g_params['l'] && (fi->grp = getgrgid(fi->stat.st_gid)) == NULL)
		return (false);
	return (true);
}
