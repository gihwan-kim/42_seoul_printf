CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft.a
SRCS = ap_c.c ap_d_i_u.c ap_p.c ap_s.c ap_x_big_x.c check_flags.c  ap_percent.c\
	check_precision.c check_specifier.c check_width.c ft_itoa_base.c\
	ft_printf.c set_output_funs_c_s.c set_output_funs_integer.c\
	set_output_funs_p.c	initialize_t_info.c set_output_funs_utils.c
OBJS = ${SRCS:%.c=%.o}

$(NAME) : $(LIBFT) $(OBJS)
	cp ./libft/$(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C ./libft all

clean :
	$(MAKE) -C ./libft clean
	rm -f *.o ${NAME}

fclean : clean all

re : fclean all
