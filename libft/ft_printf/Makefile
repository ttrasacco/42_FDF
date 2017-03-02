NAME = libftprintf.a
SRCS = ft_fill_s_arg.c ft_fill_s_arg_2.c ft_isprint.c ft_itoa.c ft_itoa_base.c \
ft_print_bad_arg.c ft_print_c.c ft_print_c_maj.c ft_print_d.c ft_print_d_maj.c \
ft_print_i.c ft_print_modulo.c ft_print_o.c ft_print_o_maj.c ft_print_p.c ft_print_s.c \
ft_print_s_maj.c ft_print_u.c ft_print_u_maj.c ft_print_x.c ft_print_x_maj.c ft_printf.c \
ft_putwchar.c ft_size_to_print.c ft_strlen.c ft_strndup.c ft_tab_functions.c ft_tmp_next.c \
ft_uitoa.c ft_uitoa_base.c ft_wstrdup.c ft_wstrlen.c
OBJ = ft_fill_s_arg.o ft_fill_s_arg_2.o ft_isprint.o ft_itoa.o ft_itoa_base.o \
ft_print_bad_arg.o ft_print_c.o ft_print_c_maj.o ft_print_d.o ft_print_d_maj.o \
ft_print_i.o ft_print_modulo.o ft_print_o.o ft_print_o_maj.o ft_print_p.o ft_print_s.o \
ft_print_s_maj.o ft_print_u.o ft_print_u_maj.o ft_print_x.o ft_print_x_maj.o ft_printf.o \
ft_putwchar.o ft_size_to_print.o ft_strlen.o ft_strndup.o ft_tab_functions.o ft_tmp_next.o \
ft_uitoa.o ft_uitoa_base.o ft_wstrdup.o ft_wstrlen.o

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -q $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all