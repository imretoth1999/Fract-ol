# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itoth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 16:54:14 by itoth             #+#    #+#              #
#    Updated: 2017/04/05 16:33:18 by itoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Werror -Wextra
SRC = main.c newton.c scales.c keys.c julia_mandel.c init_all.c hook.c ft_putstr_fd.c ft_putchar_fd.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) -lmlx -framework OpenGl -framework AppKit
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
