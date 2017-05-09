# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2017/05/09 20:09:57 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = ./src/

SRC_NAME = 	format_char.c \
			format_dec.c \
			format_hex.c \
			format_oct.c \
			format_str.c \
			format_stuff.c \
			format_udec.c \
			format_wchar.c \
			format_wstr.c \
			ft_atoi.c \
			ft_binlen.c \
			ft_bzero.c \
			ft_intlen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_itoa_base16.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_ltoi.c \
			ft_max2.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_min2.c \
			ft_nbrlen.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putwchar.c \
			ft_putwstr.c \
			ft_spacetozero.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcnt.c \
			ft_strcpy.c \
			ft_strctrim.c \
			ft_strcut.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strpad.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_strtrns.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_uitoa_base16.c \
			ft_unbrlen.c \
			ft_wstrchr.c \
			ft_wstrcut.c \
			ft_wstrdup.c \
			ft_wstrlen.c \
			ft_wstrncpy.c \
			ft_wstrnew.c \
			ft_wstrpad.c \
			get_next_line.c \
			handle_num_precision.c \
			handle_prefix.c \
			handle_prefix_x.c \
			init_specs.c \
			parse_flags.c \
			parse_length.c \
			parse_precision.c \
			parse_specs.c \
			parse_type.c \
			parse_width.c \
			strip_sign.c \
			ft_abs.c \
			ft_iswhitespace.c \
			ft_logbasen.c

OBJ_PATH = ./obj/

INC_PATH = ./includes/

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)

re:	fclean all
