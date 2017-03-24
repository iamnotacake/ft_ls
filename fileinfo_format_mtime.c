/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_mtime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:20:08 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 19:34:48 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_mtime(t_fileinfo *fi)
{
	char		*tm;

	tm = ctime(&fi->stat.st_mtime);
	ft_sprintf(fi->fmt_mtime, " %.12s", tm + 4);
}
