CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft.a
SRCS = ap_c.c ap_d_i_u.c ap_p.c ap_s.c ap_x_X.c check_flags.c check_length.c \
	check_precision.c check_specifier.c check_width.c ft_itoa_base.c ft_printf.c \
	get_set_output_funs.c initialize_format_info.c ap_percent.c\

# PRINTF_H = ./ft_printf.h
# LIBFT_H = ./libft/libft.h
OBJS = ${SRCS:%.c=%.o}

# $(NAME) : $(LIBFT) $(OBJS)
# 	$(CC) -c $(CFLAGSS) $(SRCS) -lft -L./libft
# 	# $(CC) -o $(CFLAGSS) $(OBJS)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

# libftprint.a 에 libft.a 를 복사한뒤 OBJS 들을 추가시켜주었다.
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

a.out :
	#gcc $(CFLAGSS) $(SRCS) $(PRINTF_H) $(LIBFT_H) ./libft/*.c ../printf_test/*.c  printf test case
	gcc $(SRCS) $(PRINTF_H) $(LIBFT_H) ./libft/*.c

# $(NAME) : $(OBJS) $(LIBFT)
# 	#gcc -g3 -fsanitize=address $(CFLAGSS) $(SRCS) $(PRINTF_H) $(LIBFT_H)
# 	#gcc -g3 -fsanitize=address $(SRCS) $(PRINTF_H) $(LIBFT_H) ./libft/*.c // memory check options
# 	# gcc $(SRCS) $(PRINTF_H) $(LIBFT_H) ./libft/*.c
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)
