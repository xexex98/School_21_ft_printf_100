# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/11/23 20:15:19 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRC =	ft_printf.c\
		ft_funcs_1.c\
		ft_funcs_2.c\
		ft_funcs_3.c\
		ft_funcs_4.c\

OBJS = ${SRC:.c=.o}

CC 			= gcc
RM 			= rm -f
FLAGS 		= -c -Wall -Wextra -Werror -I $(HEADER)

OBJECTS = $(patsubst %.c, %.o, $(SRC))

all: $(NAME) 

$(NAME): $(OBJECTS) $(HEADER)
	ar rcs $(NAME) $?

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
