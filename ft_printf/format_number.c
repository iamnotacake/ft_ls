/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:39:23 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 15:06:07 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*uintmax_to_any(uintmax_t n, int b, bool up)
{
	static char	res[1024];
	int			i;
	const char	*alpha;

	alpha = up ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 512;
	res[i] = '\0';
	while (true)
	{
		res[--i] = alpha[n % b];
		n /= b;
		if (n == 0)
			break ;
	}
	return (&res[i]);
}

char			*intmax_to_any(intmax_t n, int b, bool up, char *sign)
{
	*sign = n < 0 ? '-' : '\0';
	return (uintmax_to_any(n < 0 ? -n : n, b, up));
}
