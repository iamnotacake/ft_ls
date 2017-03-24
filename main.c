/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:24 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 15:57:39 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool			g_params[256];

int				main(int argc, char *argv[])
{
	char		**args;
	int			i;

	arg_parse(argc, argv, &args);
	i = 0;
	while (args[i])
	{
		ft_printf("Argument #%d: \"%s\"\n", i, args[i]);
		i++;
	}
	return (0);
}
