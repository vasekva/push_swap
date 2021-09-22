cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(includes libft/includes)

add_executable(push_swap
        libft/srcs/first_part/ft_atoi.c
        libft/srcs/first_part/ft_isdigit.c
        libft/srcs/first_part/ft_memcpy.c
        libft/srcs/first_part/ft_strchr.c
        libft/srcs/first_part/ft_strdup.c
        libft/srcs/first_part/ft_strlen.c
        libft/srcs/first_part/ft_strncmp.c

        libft/srcs/second_part/ft_split.c
        libft/srcs/second_part/ft_strjoin.c
        libft/srcs/second_part/ft_substr.c

        srcs/lists/getLast.c
        srcs/lists/listLength.c
        srcs/lists/printLinkedList.c
        srcs/lists/pushBack.c

        srcs/actions.c
        srcs/exception.c
        srcs/get_next_line.c
        srcs/little_sort.c
        srcs/main.c

        )