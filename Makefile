NAME		= miniRT

SRCS 		=  main.c \
			   read.c \
			   trgb.c \
			   coord.c \
			   vector.c \
			   figure.c \
			   sphere.c \
			   plane.c \
			   square.c \
			   data.c \
			   window.c \
			   camera.c \
			   light.c \
			   color_fx.c

OBJS		= $(SRCS:.c=.o)

LIBFT_F		= ./libft/

LIBFT		= libft.a

MLX_F		= ./mlx/

MLX			= libmlx.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

OBJ_FLAGS	= -Imlx

LINK_FLAGS	= -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

RM			= rm -f

all:		$(NAME)

$(NAME):	${OBJS}
			@$(MAKE) all -C $(LIBFT_F)
			@$(MAKE) all -C $(MLX_F)
			${CC} $(CFLAGS) $(LINK_FLAGS) -o $(NAME) $(OBJS)

.c.o:		minirt.h 	
			${CC} ${CFLAGS} ${OBJ_FLAGS} -c $< -o ${<:.c=.o}

$(OBJS):	minirt.h

clean:	
			${MAKE} clean -C $(LIBFT_F)
			@${RM} -r ${OBJS}

fclean:		clean
			${MAKE} fclean -C $(LIBFT_F)
			${MAKE} clean -C $(MLX_F)
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
