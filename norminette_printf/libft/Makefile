# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gihkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 15:47:23 by gihkim            #+#    #+#              #
#    Updated: 2020/04/20 10:19:40 by gihkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NO_B = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c 	ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRC_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
	ft_lstnew.c ft_lstsize.c

OBJS_NO_B = ${SRC_NO_B:%.c=%.o}
OBJS_B = ${SRC_B:%.c=%.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

ifdef CHECK_BONUS
	OBJS = ${OBJS_NO_B} ${OBJS_B}
else
	OBJS = ${OBJS_NO_B}
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	# ranlib $(NAME)

clean :
	rm -f $(OBJS) $(NAME) *.o a.out

fclean : clean all

re : fclean all

bonus :
	make CHECK_BONUS=1 all