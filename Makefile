include makefile.srcs

NAME			=	miniRT

SRCS_DIR		=	srcs

OBJS_DIR		=	objs

OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCLUDES		=	-Iincludes -I./libs/libft -I./libs/mlx

H_FILES			=	../includes/minirt.h								\
					includes/parsing.h								\
					includes/error.h								\
					includes/prototypes.h					\
					libs/mlx/mlx.h

XLIB			=	mlx

XLIBDIR			=	libs/mlx

LIB_MLX			=	$(XLIBDIR)/libmlx.a

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

XFLAGS			=	-lmlx -lXext -lX11 -o miniRT -lm

RM				=	rm -rf

all : $(LIB_MLX) $(NAME)

$(NAME) : $(OBJS) $(LIB_MLX)
		$(CC) $(OBJS) -L$(XLIBDIR) -l$(XLIB) $(XFLAGS) -o $(NAME)

bonus : all

.SECONDEXPANSION:
${OBJS} :	$$(patsubst %.o, %.c, $$(subst ${OBJS_DIR}/, ${SRCS_DIR}/, $${@}))
			@mkdir -p ${@D}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

-include ${OBJS:.o}

$(LIB_MLX):
			cd $(XLIBDIR) && ./configure && make;

clean :
			@$(RM) $(OBJS) $(D_FILES)
			@echo "\033[1;38;5;221m*  miniRT objects removed\033[0m"

fclean : clean
			@$(RM) $(NAME) $(LIB_MLX)
			@$(MAKE) clean -C $(XLIBDIR)
			@echo "\033[1;38;5;221m*  miniRT program removed\033[0m"

re : fclean all
.PHONY: all bonus clean fclean re