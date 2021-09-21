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
        srcs/main.c
        srcs/exception.c
        )