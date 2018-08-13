NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror

CFILES= arg_out.c \
	assigns.c \
	central_functs.c \
	inits.c \
	main.c \
	p_char.c \
	p_decimal.c \
	p_hex.c \
	p_octal.c \
	p_pointer.c \
	p_undecimal.c \
	printables.c \
	p_widestring.c \
	sign_unsign.c \
	string_it.c \
	assigns2.c	

LIBFT=./libft

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -c $(CFILES)
	ar -x libft/libft.a
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

main: all
	$(CC) -g $(NAME) *.c libft/*.c -o ft_printf

fclean: clean
	rm -f $(NAME)

re: fclean all
