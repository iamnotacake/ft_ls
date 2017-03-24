/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:47 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 16:14:52 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool			fileinfo_get(t_fileinfo *fi, const char *filename)
{
	__builtin_bzero(fi, sizeof(t_fileinfo));
	if (lstat(filename, &fi->stat) == -1)
		return (false);
	return (true);
}
