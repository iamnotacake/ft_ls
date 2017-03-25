/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_perms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:17:26 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 17:07:20 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		fileinfo_format_perms_type(t_fileinfo *fi)
{
	if (S_ISDIR(fi->stat.st_mode))
		return ('d');
	if (S_ISLNK(fi->stat.st_mode))
		return ('l');
	if (S_ISFIFO(fi->stat.st_mode))
		return ('p');
	if (S_ISCHR(fi->stat.st_mode))
		return ('c');
	if (S_ISBLK(fi->stat.st_mode))
		return ('b');
	return ('-');
}

static char		fileinfo_format_perms_exec(t_fileinfo *fi, int who)
{
	if (fi->stat.st_mode & who)
		return ('s');
	if (fi->stat.st_mode & S_IXUSR)
		return ('x');
	return ('-');
}

void			fileinfo_format_perms(t_fileinfo *fi)
{
	ft_sprintf(fi->fmt_perms, "%c%c%c%c%c%c%c%c%c%c%c ",
				fileinfo_format_perms_type(fi),
				fi->stat.st_mode & S_IRUSR ? 'r' : '-',
				fi->stat.st_mode & S_IWUSR ? 'w' : '-',
				fileinfo_format_perms_exec(fi, S_ISUID),
				fi->stat.st_mode & S_IRGRP ? 'r' : '-',
				fi->stat.st_mode & S_IWGRP ? 'w' : '-',
				fileinfo_format_perms_exec(fi, S_ISGID),
				fi->stat.st_mode & S_IROTH ? 'r' : '-',
				fi->stat.st_mode & S_IWOTH ? 'w' : '-',
				fi->stat.st_mode & S_IXOTH ? 'x' : '-',
				fi->xattr[0] != '\0' ? '@' : ' ');
}
