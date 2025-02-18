NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =		main.c \
			draw.c \
			hook.c \
			init.c \
			offset.c \
			r_map.c \
			utils.c \
			utils_draw.c \
			utils2.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) libmlx.a
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

libmlx.a:
	make -C mlx
	cp mlx/libmlx.a .

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	make -C mlx clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) libmlx.a

re: fclean all

git:
	git status
	git add .
	git commit -m "auto update"
	git push

.PHONY: all clean fclean re