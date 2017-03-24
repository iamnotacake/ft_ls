/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 16:02:33 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <sys/stat.h>
# include <stdbool.h>
# include "ft_printf.h"

# define PROGNAME "ft_ls"

# define IS_PARAM(c) (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't')

typedef struct	s_fileinfo
{
	struct stat	stat;
}				t_fileinfo;

bool			g_params[256];

void			arg_error(char chr);
void			arg_parse(int argc,
							char *argv[],
							char *(*args[]));

#endif
