# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 13:09:20 by alischyn          #+#    #+#              #
#    Updated: 2017/03/28 17:18:45 by alischyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Ift_printf
LDFLAGS = -Lft_printf -lftprintf
SOURCES = main.c \
		  arg_parser.c \
		  fileinfo.c \
		  fileinfo_format.c \
		  fileinfo_format_perms.c \
		  fileinfo_format_nlinks.c \
		  fileinfo_format_owner_name.c \
		  fileinfo_format_owner_group.c \
		  fileinfo_format_size.c \
		  fileinfo_format_mtime.c \
		  fileinfo_format_name.c \
		  vec_alloc.c \
		  vec_stack.c \
		  vec_iter.c \
		  vec_sort.c \
		  ls_pre_main.c \
		  ls_main.c \
		  ls_print.c \
		  ls_print_prepare.c \
		  sort.c
OBJECTS = $(addprefix obj/,$(subst .c,.o,$(SOURCES)))
NAME = ft_ls

ifeq ($(DEBUG),1)
CFLAGS += -g
else
CFLAGS += -O3
endif

all: $(NAME)

$(NAME): $(OBJECTS) ft_printf/libftprintf.a
	$(CC) -o $@ $^ $(LDFLAGS)

obj/%.o: %.c *.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

ft_printf/libftprintf.a:
	make -C ft_printf

clean:
	rm -rf obj
	make -C ft_printf clean

fclean:
	rm -rf obj $(NAME)
	make -C ft_printf fclean

re: fclean all

norm:
	norminette *.c *.h
