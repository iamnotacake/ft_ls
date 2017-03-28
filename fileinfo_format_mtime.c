/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_mtime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:20:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/28 18:00:23 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_mtime(t_fileinfo *fi)
{
	char		time_str[64];
	char		*tm;
	time_t		curr_time;

	time(&curr_time);
	tm = ctime(&curr_time);
	__builtin_strcpy(time_str, tm);
	tm = ctime(&fi->stat.st_mtime);
	__builtin_strcpy(time_str + 32, tm);
	ft_sprintf(fi->fmt_mtime, "%.7s%.5s ",
				time_str + 32 + 4,
				__builtin_strncmp(time_str + 20, time_str + 32 + 20, 4) == 0
					? time_str + 32 + 11
					: time_str + 32 + 19);
}
