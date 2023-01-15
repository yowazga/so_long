# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 16:37:00 by yowazga           #+#    #+#              #
#    Updated: 2023/01/15 12:31:25 by yowazga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
BNAME := so_long_bonus

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC = man/main.c \
	man/check_map.c \
	man/alloc_content.c \
	man/ft_split.c \
	man/mini_libft.c \
	man/mouvment.c \
	man/start_map.c \
	man/valid_path.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	man/first_free_file.c \
	man/second_free_file.c

SRC_B = bns/main_bonus.c \
	bns/check_map_bonus.c \
	bns/alloc_content_bonus.c \
	bns/ft_split_bonus.c \
	bns/mini_libft_bonus.c \
	bns/mouvment_bonus.c \
	bns/start_map_bonus.c \
	bns/valid_path_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	bns/first_free_file_bonus.c \
	bns/second_free_file_bonus.c \
	bns/ft_animation_bonus.c \
	bns/put_enemy_bonus.c

OBJ := $(SRC:.c=.o)
OBJ_B := $(SRC_B:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(BNAME)

$(BNAME):$(OBJ_B)
	$(CC) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

%.o: %.c man/so_long.h bns/so_long_bonus.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	@echo rm the file .o
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@echo rm file programe
	@rm -f $(NAME) $(BNAME)

re : fclean all

reb : fclean bonus

.PHONY : all clean fclean re bonus reb