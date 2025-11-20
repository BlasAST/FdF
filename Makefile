NAME    = fdf
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c \
		utils_main.c \
		check_file.c \
		utils_file.c \
		parse.c \
		utils_parse.c \
		check_parse.c \
		functions_win.c \
		matrix.c \
		draw.c \
		utils_draw.c \
		errors.c \
		exits.c \
		frees.c \
		ft_atoi_base.c 
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft bonus
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a \
	-L minilibx-linux/ -lmlx -lXext -lX11 -lm
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C libft clean_bonus
	make -C minilibx-linux clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean_bonus
re: fclean all

.PHONY: all clean fclean re