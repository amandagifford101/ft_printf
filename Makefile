# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agifford <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 14:37:22 by agifford          #+#    #+#              #
#    Updated: 2018/08/10 13:49:56 by agifford         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC: gcc
CFLAGS: -g -Wall -Werror -Wextra
STD:   main.c /
	ft_printf.h /
	central_functs.c /
	inits.c /
	assigns.c /
	arg_out.c /
	string_it.c /
	p_wide_string.c /
	p_pointer.c /
	p_char.c /
	p_decimal.c /
	p_octal.c /
	p_hex.c/
TEST: 	ft_printf.h /
	inits.c /
	libft /
	print_arg_test.c /
	testy.c /

LIBFT = -I libs/libft -L libs/libft -lft
LIBS = $(LIBFT)

all: $(NAME)

$(NAME): -lft $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -I include $(OBJ) -o $@

SRC = $(addprefix src/, $(STD) $(TEST))
OBJ = $(addprefix obj/, $(STD:.c=.o) $(TEST:.c=.o))

obj:
	mkdir obj

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -I libs/libft -I includes -c $< -o $@

-lft:
	$(MAKE) -C libs/libft

clean:
	$(MAKE) -C libs/libft clean
	/bin/rm -rf obj

fclean: clean
	$(MAKE) -C libs/libft fclean
	/bin/rm -f $(NAME)

re: fclean all
