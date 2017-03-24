/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unknown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:30:35 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:01:24 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_unknown(t_fmt *fmt)
{
	if (fmt->has_width && !fmt->f_minus)
		APPEND_CHAR_N(fmt->f_zero ? '0' : ' ', fmt->width - 1);
	APPEND_CHAR(fmt->type);
	if (fmt->has_width && fmt->f_minus)
		APPEND_CHAR_N(' ', fmt->width - 1);
}
