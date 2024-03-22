NAME = so_long

SRC = so_long.c images.c check_enemys_around.c player_moves.c enemy_moves.c ft_free.c map_checks.c map_check_utils.c ft_split.c check_elements_count.c ft_strlcpy.c get_next_line_utils.c get_next_line.c ft_printf.c ft_putchar.c ft_putstr.c window_checks.c

CFLAGS = -Wall -Wextra -Werror 

FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) :
	cc   $(CFLAGS) $(SRC)  $(FLAGS) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
