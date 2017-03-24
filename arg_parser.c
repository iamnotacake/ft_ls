/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:15:50 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 15:56:31 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			arg_error(char chr)
{
	ft_printf("%s: illegal option -- %c\n", PROGNAME, chr);
	ft_printf("usage: %s [-alrRt] [file ...]\n", PROGNAME);
	exit(1);
}

void			arg_parse(int argc,
							char *argv[],
							char *(*args[]))
{
	int			i;
	int			j;

	__builtin_bzero(g_params, sizeof(g_params));
	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0')
		{
			i++;
			break ;
		}
		j = 0;
		while (argv[i][++j] != '\0')
		{
			if (IS_PARAM(argv[i][j]))
				g_params[(int)argv[i][j]] = true;
			else
				arg_error(argv[i][j]);
		}
	}
	*args = &argv[i];
}
