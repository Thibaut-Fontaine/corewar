# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2017/05/02 17:24:53 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = src/

SRC_NAME =	extract_labeldecl.c \
			is_labelchar.c \
			extract_indirect.c \
			extract_direct.c \
			extract_labeldecl.c \
			extract_op.c \
			extract_register.c \
			extract_string.c \
			extract_command.c \
			test_extracts.c \
			token_init.c \
			ft_isendl.c \
			get_token.c \
			generate_op_from_line.c

OBJ_PATH = obj/

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = asm

CC = clang
CFLAGS = -Werror -Wall -Wextra -g -O0

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
