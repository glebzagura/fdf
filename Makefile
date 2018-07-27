# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gzagura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 22:50:29 by gzagura           #+#    #+#              #
#    Updated: 2018/07/27 22:50:33 by gzagura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Werror -Wextra
NAME		= fdf
SCR 		= src/main_fdf.c src/ft_open_proc.c src/lstworker.c src/ft_strwork.c src/ft_getnbr.c src/bresen.c src/get_next_line.c src/ft_atoi_base.c src/ft_draw.c
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS)  $(SCR) -I /usr/local/include -I -r ././libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

./libft/libft.a:
	@$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
