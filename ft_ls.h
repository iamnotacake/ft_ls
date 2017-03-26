/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:09:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/26 18:54:08 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <stdbool.h>
# include <string.h>
# include <time.h>
# include "ft_printf.h"
# include "vec.h"

# define PROGNAME "ft_ls"

# define IS_PARAM(c) (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't')

typedef struct	s_fileinfo
{
	struct stat		stat;
	struct passwd	*pwd;
	struct group	*grp;
	char			xattr[4096];
	char			name[256];
	char			lnk_dest[256];
	char			fmt_perms[16];
	char			fmt_nlinks[8];
	int				fmt_nlinks_pad;
	char			fmt_owner_name[32];
	int				fmt_owner_name_pad;
	char			fmt_owner_group[32];
	int				fmt_owner_group_pad;
	char			fmt_size[16];
	char			fmt_mtime[24];
	char			fmt_name[512];
}				t_fileinfo;

typedef struct	s_list
{
	char		path[512];
	bool		print_path;
	t_fileinfo	fileinfo;
	t_vec		items;
}				t_list;

bool			g_params[256];

void			arg_error(char chr);
void			arg_parse(int argc,
							char *argv[],
							char *(*args[]));

bool			fileinfo_get(t_fileinfo *fi, const char *filename, bool single);

void			fileinfo_format(t_fileinfo *fi);
void			fileinfo_format_perms(t_fileinfo *fi);
void			fileinfo_format_nlinks(t_fileinfo *fi);
void			fileinfo_format_owner_name(t_fileinfo *fi);
void			fileinfo_format_owner_group(t_fileinfo *fi);
void			fileinfo_format_size(t_fileinfo *fi);
void			fileinfo_format_mtime(t_fileinfo *fi);
void			fileinfo_format_name(t_fileinfo *fi);

void			ls_pre_main(t_vec *list);

void			ls_main_singles(t_fileinfo **fi, int count);
void			ls_main_dirs(t_fileinfo **fi, int count, bool x);

void			ls_print_list(t_list *list);

void			ls_print_list_prepare_nlinks_pad(t_list *list);
void			ls_print_list_prepare_owner_name_pad(t_list *list);
void			ls_print_list_prepare_owner_group_pad(t_list *list);

#endif
