/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:24 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/25 19:34:07 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool			g_params[256];

int				main(int argc, char *argv[])
{
	char		**args;
	int			i;
	t_vec		vec;

	arg_parse(argc, argv, &args);
	vec_init(&vec);
	i = 0;
	while (args[i] != NULL)
	{
		vec_push(&vec, args[i]);
		i++;
	}
	if (args[0] == NULL)
		vec_push(&vec, ".");
	ls_pre_main(&vec);
	vec_free(&vec, false);
	return (0);
}
