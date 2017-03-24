/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:48 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 19:12:12 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include "str.h"

# define APPEND_CHAR(c)			str_append_char(&g_res, (c))
# define APPEND_CHAR_N(c, n)	str_append_char_n(&g_res, (c), (n))
# define APPEND_STRING(c)		str_append_string(&g_res, (c))
# define APPEND_STRING_N(c, n)	str_append_string_n(&g_res, (c), (n))

# define IS_CHAR(f)		(f->type == 'c' || f->type == 'C')
# define IS_STRING(f)	(f->type == 's')
# define IS_WSTRING(f)	(!STRCMP(f->mod, "l") && IS_STRING(f) || f->type == 'S')
# define IS_DECIMAL(f)	(f->type == 'd' || f->type == 'D' || f->type == 'i')
# define IS_UNSIGNED(f)	(f->type == 'u' || f->type == 'U')
# define IS_OCTAL(f)	(f->type == 'o' || f->type == 'O')
# define IS_HEX(f)		(f->type == 'x' || f->type == 'X' || f->type == 'p')

typedef struct	s_fmt
{
	bool	f_plus;
	bool	f_minus;
	bool	f_zero;
	bool	f_octo;
	bool	f_space;
	bool	has_width;
	int		width;
	bool	has_precision;
	int		precision;
	char	mod[3];
	char	type;
}				t_fmt;

t_str			g_res;

int				ft_printf(const char *format, ...);
int				ft_fdprintf(int fd, const char *format, ...);
int				ft_sprintf(char *dest, const char *format, ...);
int				ft_asprintf(char **dest, const char *format, ...);

const char		*parse(t_fmt *fmt, const char *f, va_list ap);
const char		*parse_flags(t_fmt *fmt, const char *f);
const char		*parse_width(t_fmt *fmt, const char *f, va_list ap);
const char		*parse_precision(t_fmt *fmt, const char *f, va_list ap);
const char		*parse_mod(t_fmt *fmt, const char *f);

void			format_fmt(t_fmt *fmt, va_list ap);

void			format_unknown(t_fmt *fmt);

void			format_char(t_fmt *fmt, va_list ap);

void			format_wstring(t_fmt *fmt, va_list ap);
void			format_string(t_fmt *fmt, va_list ap);

uintmax_t		pull_number_unsigned(t_fmt *fmt, va_list ap);
intmax_t		pull_number_signed(t_fmt *fmt, va_list ap);

char			*uintmax_to_any(uintmax_t n, int b, bool up);
char			*intmax_to_any(intmax_t n, int b, bool up, char *sign);

char			*format_number_prep_zeros(t_fmt *fmt, char *number);
bool			number_is_zero(const char *number);
void			format_number_decimal(t_fmt *fmt, va_list ap);

void			format_number_octal(t_fmt *fmt, va_list ap);

void			format_number_hexadecimal(t_fmt *fmt, va_list ap);

void			format_n(t_fmt *fmt, va_list ap);

#endif
