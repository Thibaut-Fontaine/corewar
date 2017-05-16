# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 09:59:01 by jgagnot           #+#    #+#              #
#    Updated: 2017/03/13 10:00:02 by jgagnot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c\
			add_argument.c\
			add_label_to_list.c\
			add_operation.c\
			asm_init.c\
			check_labels_error.c\
			check_param_error.c\
			check_param_number.c\
			extract_instruction.c\
			extract_labeldecl.c\
			extract_params.c\
			ft_error.c\
			generate_bytecode.c\
			get_arg_type.c\
			get_op_size.c\
			get_operation_type.c\
			init_optab.c\
			is_labelchar.c\
			param_parser_init.c\
			parse.c\
			parse_argument.c\
			parse_comment.c\
			parse_header.c\
			parse_name.c\
			remove_com.c\
			write_args.c\
			write_code.c\
			write_header.c\
			write_number.c\
			write_octalcoding.c\
			write_op.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lm -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

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
