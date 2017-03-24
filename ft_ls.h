/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 15:51:49 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <stdbool.h>
# include "ft_printf.h"

# define PROGNAME "ft_ls"

# define IS_PARAM(c) (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't')

bool			g_params[256];

void			arg_error(char chr);
void			arg_parse(int argc,
							char *argv[],
							char *(*args[]));

#endif
