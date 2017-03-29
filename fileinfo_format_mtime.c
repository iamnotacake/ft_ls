/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_mtime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:20:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/29 17:43:43 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_mtime(t_fileinfo *fi)
{
	char		tm_now[32];
	time_t		time_now;
	char		tm_file[32];
	char		*tm;
	bool		same_year;

	time(&time_now);
	tm = ctime(&time_now);
	__builtin_strcpy(tm_now, tm);
	tm = ctime(&fi->stat.st_mtime);
	__builtin_strcpy(tm_file, tm);
	same_year = time_now - fi->stat.st_mtime < 60 * 60 * 24 * 182;
	ft_sprintf(fi->fmt_mtime, "%.7s%.5s ",
				tm_file + 4, same_year ? tm_file + 11 : tm_file + 19);
}
