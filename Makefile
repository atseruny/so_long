CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra #-Werror

MLX_DIR = minilibx-linux

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


SRC = main.c get_next_line.c get_next_line_utils.c validation.c val.c start.c movement.c map.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) so_long.h Makefile
	$(CC) $(OBJ) $(LIBFT) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) 
#-fsanitize=address -g3

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
