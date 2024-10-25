# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:23:04 by jolivare          #+#    #+#              #
#    Updated: 2024/10/25 12:23:06 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = src/init_map.c inc/get_next_line/get_next_line.c src/errors/print_errors.c src/cub3d.c \
		src/parser/parse_config.c utils/free.c
OBJ = $(SRC:.c=.o)
LIBFT = inc/libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I inc/libft
MLX_FLAGS = -L ./mlx -lmlx -lXext -lX11 -lm

all: $(NAME)

$(LIBFT):
	@printf "$(Y)Compiling libft...$(END)\n"
	@$(MAKE) -sC inc/libft/
	@printf "$(G)Libft:\t\tcompiled!📚$(END)\n"

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

clean:
	make clean -sC inc/libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -sC inc/libft/
	rm -f $(NAME)

c: all clean

re: fclean all