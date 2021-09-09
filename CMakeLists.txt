cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)
include_directories(libft/includes)

add_executable(push_swap
        libft/srcs/first_part/ft_atoi.c
        libft/srcs/first_part/ft_isdigit.c
        libft/srcs/first_part/ft_strlen.c
        libft/srcs/second_part/ft_split.c
        libft/srcs/second_part/ft_substr.c
        libft/srcs/bonus_part/ft_lstadd_back.c
        libft/srcs/bonus_part/ft_lstadd_front.c
        libft/srcs/bonus_part/ft_lstclear.c
        libft/srcs/bonus_part/ft_lstdelone.c
        libft/srcs/bonus_part/ft_lstiter.c
        libft/srcs/bonus_part/ft_lstlast.c
        libft/srcs/bonus_part/ft_lstmap.c
        libft/srcs/bonus_part/ft_lstnew.c
        srcs/main.c
        srcs/exception.c
        )