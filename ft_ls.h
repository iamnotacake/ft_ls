/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 19:06:01 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <stdbool.h>
# include "ft_printf.h"

# define PROGNAME "ft_ls"

# define IS_PARAM(c) (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't')

typedef struct	s_fileinfo
{
	struct stat		stat;
	struct passwd	*pwd;
	struct group	*grp;
	char			xattr[4096];
	char			fmt_perms[16];
	char			fmt_nlinks[8];
	char			fmt_owner_name[32];
	char			fmt_owner_group[32];
	char			fmt_size[16];
}				t_fileinfo;

bool			g_params[256];

void			arg_error(char chr);
void			arg_parse(int argc,
							char *argv[],
							char *(*args[]));

bool			fileinfo_get(t_fileinfo *fi, const char *filename);

void			fileinfo_format(t_fileinfo *fi);
void			fileinfo_format_perms(t_fileinfo *fi);
void			fileinfo_format_nlinks(t_fileinfo *fi);
void			fileinfo_format_owner_name(t_fileinfo *fi);
void			fileinfo_format_owner_group(t_fileinfo *fi);
void			fileinfo_format_size(t_fileinfo *fi);

#endif
