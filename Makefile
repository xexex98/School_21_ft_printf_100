# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/10/21 13:37:48 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\

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