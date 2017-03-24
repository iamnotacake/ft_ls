# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 13:09:20 by alischyn          #+#    #+#              #
#    Updated: 2017/03/24 13:12:43 by alischyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c
OBJECTS = $(addprefix obj/,$(subst .c,.o,$(SOURCES)))
NAME = ft_ls

ifeq ($(DEBUG),1)
CFLAGS += -g
else
CFLAGS += -O3
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^

obj/%.o: %.c *.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj

fclean:
	rm -rf obj $(NAME)

re: fclean all

norm:
	norminette *.c *.h
