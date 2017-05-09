# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 09:59:01 by jgagnot           #+#    #+#              #
#    Updated: 2017/05/09 19:41:38 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CFLAGS = -Wall -Wextra -Werror

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = bytegen.c \
			generate_bytecode.c \
			init_optab.c \
			make_example_asm.c \
			write_header.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lm -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -g -fsanitize=address


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
