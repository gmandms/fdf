NAME = fdf

SRC = ./new_file1.c ./new_file2.c ./bresenham.c ./draw_map.c ./get_next_line.c ./main.c ./read.c

LIBFT = ./libft

MLX = ./minilibx_macos

LIB_MAC = -lmlx -lm -lft -L $(LIBFT) -L $(MLX) -framework OpenGL -framework APPKit

FLAGS = -Wall -Wextra

all: $(NAME)

lib_compile:
	make -C $(LIBFT)
	make -C $(MLX)

$(NAME): lib_compile
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB_MAC)

clean:
	make -C $(LIBFT) fclean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
