/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_owner_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:33:21 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 18:28:38 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_owner_name(t_fileinfo *fi)
{
	ft_sprintf(fi->fmt_owner_name, "%s ", fi->pwd->pw_name);
}
