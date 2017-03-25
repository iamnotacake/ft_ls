/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_owner_group.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:34:38 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 19:54:19 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_owner_group(t_fileinfo *fi)
{
	ft_sprintf(fi->fmt_owner_group, "%s  ", fi->grp->gr_name);
}
