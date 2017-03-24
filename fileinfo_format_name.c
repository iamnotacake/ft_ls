/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_format_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:43:21 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 19:52:43 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fileinfo_format_name(t_fileinfo *fi)
{
	__builtin_strcpy(fi->fmt_name, fi->name);
}
