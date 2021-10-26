# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/10/26 12:27:44 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c\
		ft_hexlen.c\
		ft_intlen.c\
		ft_print_c.c\
		ft_print_id.c\
		ft_print_p.c\
		ft_print_s.c\
		ft_print_ud.c\
		ft_print_ux.c\
		ft_print_x.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putnbruns_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\

OBJS = ${SRC:.c=.o}

CC 			= gcc
RM 			= -rm -f
FLAGS 		= -Wall -Wextra -Werror -I

# bonus: 

all:		${NAME}
${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY: bonus all clean fclean re