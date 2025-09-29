NAME = fdf
CC = cc
C_FLAGS = -Wall -Werror -Wextra

SRC= main.c \
	functions_win.c \
	events.c \
	draw.c \
	utils_file.c \
	errors.c

OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C libft
		$(CC) $(OBJ_SRC) -Lminilibx-linux/ -lmlx -lXext -lX11 \
		-o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a
%.o : %.c
	$(CC) $(FLAGS_CC) -c $< -o $@

clean:
	rm -f $(OBJ_SRC)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re