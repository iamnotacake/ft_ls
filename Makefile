# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 13:09:20 by alischyn          #+#    #+#              #
#    Updated: 2017/03/24 15:05:15 by alischyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Ift_printf
LDFLAGS = -Lft_printf -lftprintf
SOURCES = main.c \
		  arg_parser.c
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
