/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:59:44 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/26 16:18:09 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_main_singles(t_fileinfo **fi, int count, bool newline_after)
{
	int			i;

	ft_printf("Listing %d single items:\n", count);
	i = 0;
	while (i < count)
		ft_printf("> %s\n", fi[i++]->name);
	if (newline_after)
		ft_printf("\n");
}

void			ls_main_dirs(t_fileinfo **fi, int count)
{
	int			i;

	ft_printf("Listing %d dirs:\n", count);
	i = 0;
	while (i < count)
		ft_printf("> %s\n", fi[i++]->name);
}
