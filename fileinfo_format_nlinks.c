/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_nlinks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:15:15 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 17:28:56 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_nlinks(t_fileinfo *fi)
{
	ft_sprintf(fi->fmt_nlinks, "%d ", fi->stat.st_nlink);
}
