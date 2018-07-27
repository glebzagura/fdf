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
SCR 		= main.c ft_open_proc.c lstworker.c ft_strwork.c ft_getnbr.c bresen.c get_next_line.c
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean test

all: $(NAME)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS)  $(SCR) -I /usr/local/include -I -r ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

./libft/libft.a:
	@$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(CFILES)

test: test.c $(NAME)
	gcc -o $@ $^ $(CFLAGS)

