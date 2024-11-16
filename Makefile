# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 16:59:43 by alisseye          #+#    #+#              #
#    Updated: 2024/11/16 01:21:05 by alisseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c srcs/get_next_line.c srcs/load_map.c \
	srcs/load_map_utils.c srcs/utils.c srcs/validate_map.c \
	srcs/run_mlx.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re