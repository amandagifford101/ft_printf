NAME = ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
FILES = arg_out.c assigns.c assigns2.c central_functs.c inits.c \
		p_char.c p_decimal.c p_hex.c p_octal.c p_pointer.c p_undecimal.c \
		p_widestring.c printables.c sign_unsign.c string_it.c 

SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix obj/, $(FILES:.c=.o))

LIBFT = -I libs/libft -L libs/libft -lft
LIBS = $(LIBFT)

all: $(NAME)

$(NAME): -lft $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -I includes $(OBJ) -o $@

obj:
	mkdir obj

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -I libs/libft -I includes -c $< -o $@

-lft:
	$(MAKE) -C libs/libft #re

clean:
	$(MAKE) -C libs/libft clean
	/bin/rm -rf obj

fclean: clean
	$(MAKE) -C libs/libft fclean
	/bin/rm -f $(NAME)

re: fclean all
