NAME 				=	libft.a

INCLUDES			=	-I ./includes/

OBJS_DIR			=	./objs/
SRCS_DIR			=	./srcs/

SRCS_NAME			=	ft_strlen.c	ft_isdigit.c ft_atoi.c

OBJS_NAME			=	$(SRCS_NAME:.c=.o)

SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror

all:					$(NAME)

$(NAME):				$(OBJS)
						@echo "\033[1m\033[36m	===	COMPILATION LIBFT ...				\033[1m==="
						@ar -rc		$(NAME)			$(OBJS)
						@ranlib		$(NAME)
						@echo "\033[36m	===	COMPILATION LIBFT \033[32mOK			\033[36m\033[1m==="

$(OBJS):				$(SRCS)
						@($(CC)		$(INCLUDES) -c	$(SRCS))
						@(mkdir 	-p 				$(OBJS_DIR))
						@(mv 		$(OBJS_NAME)	$(OBJS_DIR))

clean:
						@(rm -rf	$(OBJS))

fclean:					clean
						@(rm -rf	$(NAME))
						@echo "\033[1m\033[36m	===	REMOVING libft.a 	\033[32mOK			\033[1m\033[36m==="
						@(rm -rf	objs)
						@echo "\033[1m\033[36m	===	REMOVING ./libft/objs	\033[32mOK			\033[1m\033[36m==="
						@echo	"\033[1m\033[36m	===	DIRECTORY LIBFT CLEANED \033[32mSUCCESSFULLY		\033[1m\033[36m==="

re:						fclean all

.PHONY:					clean fclean re all