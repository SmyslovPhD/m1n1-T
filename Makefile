NAME		= miniRT

SRCS 		=  main.c \
			   read.c \
			   trgb.c \
			   coord.c \
			   vector.c \
			   figure.c \
			   sphere.c \
			   plane.c \
			   triangle.c \
			   cylinder.c \
			   square.c \
			   data.c \
			   window.c \
			   camera.c \
			   shot.c \
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

SCRSHT_F	= screenshots

LINK_FLAGS	= -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

RM			= rm -rf

all:		$(NAME)

$(NAME):	${OBJS}
			$(MAKE) all -C $(LIBFT_F)
			$(MAKE) all -C $(MLX_F)
			${CC} $(CFLAGS) $(LINK_FLAGS) -o $(NAME) $(OBJS)
			mkdir -p ${SCRSHT_F}

.c.o:		minirt.h 	
			${CC} ${CFLAGS} ${OBJ_FLAGS} -c $< -o ${<:.c=.o}

$(OBJS):	minirt.h

clean:
			${MAKE} clean -C $(LIBFT_F)
			${RM} -r ${OBJS}

fclean:		clean
			${MAKE} fclean -C $(LIBFT_F)
			${MAKE} clean -C $(MLX_F)
			${RM} ${NAME}
			${RM} ${SCRSHT_F}

re:			fclean all

.PHONY:		all clean fclean re
