NAME		=	push_swap

INCLUDES		=	-I ./includes/
LIBFT_DIR		=	./libft/
LIBRARY			=	./libft/libft.a
SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/

SRCS_NAME		=	actions.c exception.c get_next_line.c little_sort.c little_sort_reverse.c \
					main.c push_stack_b.c sort_five_and_four_nums.c big_sort.c insert_to_b.c utils.c \
					push_from_a_to_b.c parse_functions.c \

LISTS_FUNCS		=	find_max_value.c find_min_value.c get_last.c list_length.c \
                    push_back.c put_past_pointers.c get_nth.c \

OBJS_NAME	=	$(SRCS_NAME:.c=.o) $(LISTS_FUNCS:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME)) $(addprefix $(SRCS_DIR), $(addprefix lists/, $(LISTS_FUNCS)))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror -g

.PHONY:			all	clean	fclean	re

all: 			$(NAME)

$(NAME):		$(OBJS)
				@echo "\033[1m\033[35m===	COMPILATION PUSH_SWAP...			\033[1m==="
				@$(MAKE)	-C			$(LIBFT_DIR)
				@$(CC)	$(LIBRARY)	$(OBJS)	-o $(NAME)
				@echo "\033[1m\033[35m===	PUSH_SWAP COMPILATION WAS \033[32mSUCCESFULL		\033[1m\033[35m===\n"

$(OBJS):		$(SRCS)
				@$(CC)	$(INCLUDES)	-c	$(SRCS)
				@mkdir	-p				$(OBJS_DIR)
				@mv		$(OBJS_NAME)	$(OBJS_DIR)

clean:
				@echo "\033[1m\033[35m===	CLEANING ALL OBJS FILES ...			\033[1m==="
				@echo "\033[1m\033[36m	===	CLEANING LIBFT OBJS ...				\033[1m==="
				@$(MAKE)	clean	-C		$(LIBFT_DIR)
				@echo "\033[1m\033[36m	===	CLEANING LIBFT OBJS \033[32mOK				\033[36m\033[1m==="
				@echo "\033[1m\033[36m	===	CLEANING PUSH_SWAP OBJS ...			\033[1m==="
				@rm -rf	$(OBJS)
				@echo "\033[1m\033[36m	===	CLEANING PUSH_SWAP OBJS \033[32mOK			\033[1m\033[36m==="
				@echo "\033[1m\033[35m===	ALL OBJS FILES HAVE BEEN CLEANED \033[32mSUCCESSFULLY	\033[35m\033[1m===\n"

fclean:			clean
				@echo "\033[1m\033[35m===	DELETING DIRECTORIES AND OTHER FILES...		===\033[0m"
				@$(MAKE)	fclean	-C		$(LIBFT_DIR)
				@rm -rf	$(NAME)
				@echo "\033[1m\033[36m	===	REMOVING push_swap 	\033[32mOK			\033[1m\033[36m==="
				@rm -rf	$(OBJS_DIR)
				@echo "\033[1m\033[36m	===	REMOVING ./objs		\033[32mOK			\033[1m\033[36m==="
				@echo	"\033[1m\033[35m===	ALL CREATED FILES HAVE BEEN \033[32mDELETED SUCCESSFULLY \033[1m\033[35m==="

re:				fclean all