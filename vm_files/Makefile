# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:52:55 by tfontain          #+#    #+#              #
#    Updated: 2017/05/08 07:28:44 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
HEADER = ./vm.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ./argv_parser.c ./error.c ./flag.c ./generator.c ./main.c ./open_file.c \
	  ./print.c

OBJ = $(addsuffix .o,$(basename $(SRC)))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ../libft/
	$(CC) $(FLAG) $(OPTION) $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L/ ../libft/libft.a
%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
	make -C ../libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C ../libft/ fclean
	rm -f $(NAME)

re : fclean all
