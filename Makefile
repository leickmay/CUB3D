HEADER		= includes/cub3d.h minilibx/mlx.h

SRCS		=	bitmap.c draw.c ft_error.c game_over.c get_colors.c get_map.c get_sprites.c init_camera.c \
				main.c map_error.c map_utils.c move.c parse_map.c raycasting.c sprites.c utils.c parsing_utils.c \
				parsing_utils_bis.c

MLX			=	libmlx.a

LIBFT		=	libft.a

NAME		=	cub3D

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

OBJS		=	$(SRCS:.c=.o)
.c.o: ./includes/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C ./libft
			$(MAKE) -C ./minilibx
			cp libft/libft.a .
			cp minilibx/libmlx.a .
			$(CC) -o $(NAME) $(SRCS) $(LIBFT) $(MLX) -framework OpenGL -framework Appkit

all :	$(NAME)

clean : 
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx
		rm -rf $(OBJS)

fclean :
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./minilibx
		rm -rf $(OBJS) libmlx.a libft.a cub3D
	
re :	fclean all

.PHONY : clean fclean re all