# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 22:20:55 by ttrasacc          #+#    #+#              #
#    Updated: 2017/02/28 22:20:58 by ttrasacc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = draw.c fdf.c ft_parsing.c get_next_line.c
OBJ = draw.o fdf.o ft_parsing.o get_next_line.o

$(NAME) :
	make -C ./libft re
	cp libft/libftprintf.a .
	cp libft/libftprintf.h .
	pwd
	gcc -Werror -Wall -Wextra -c $(SRCS) 
	gcc $(OBJ) libftprintf.a libmlx.a -lmlx -framework OpenGL -framework AppKit -o fdf;

all : $(NAME)

clean :
	/bin/rm -f $(OBJ)
	make -C ./libft clean
	make -C ./libft/ft_printf clean

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all