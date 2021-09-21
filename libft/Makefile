NAME 				=	libft.a

INCLUDES			=	-I ./includes/

FIRST_DIR			=	./srcs/first_part/
SECOND_DIR			=	./srcs/second_part/
BONUS_DIR			=	./srcs/bonus_part/
OBJS_DIR			=	./objs/

FIRST_PART			=	ft_atoi.c \
						ft_isdigit.c \
						ft_memcpy.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_strlen.c	\
						ft_strncmp.c \

SECOND_PART			=	ft_split.c \
						ft_strjoin.c \
						ft_substr.c \

OBJS_NAME		=	$(FIRST_PART:.c=.o) $(SECOND_PART:.c=.o)

SRCS			=	$(addprefix $(FIRST_DIR),	$(FIRST_PART))	$(addprefix $(SECOND_DIR), $(SECOND_PART))
OBJS			=	$(addprefix $(OBJS_DIR),	$(FIRST_PART:.c=.o))	$(addprefix $(OBJS_DIR), $(SECOND_PART:.c=.o))
CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

all:					$(NAME)

$(NAME):				$(OBJS)
						@echo "\033[1m\033[36m	===	COMPILATION LIBFT ...				\033[1m==="
						@ar -rc		$(NAME)			$(OBJS)
						@ranlib		$(NAME)
						@echo "\033[36m	===	COMPILATION LIBFT \033[32mOK			\033[36m\033[1m==="

$(OBJS):				$(SRCS)
						@($(CC)		$(INCLUDES) -c	$(SRCS))
						@(mkdir 	-p 				$(OBJS_DIR))
						@mv $(OBJS_NAME) $(OBJS_DIR)
						@#mv $(BONUS_PART:.c=.o) $(OBJS_DIR)

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