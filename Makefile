NAME = libftprintf.a
OBJ = $(TARG:.c=.o)
TARG = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_hex.c
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):$(TARG)
	$(CC) -c $(TARG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all