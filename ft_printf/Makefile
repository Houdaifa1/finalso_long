NAME = libftprintf.a
SOURCES =  ft_printf.c ft_putchar.c ft_putstr.c

OBJECTS = ft_printf.o ft_putchar.o ft_putstr.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
