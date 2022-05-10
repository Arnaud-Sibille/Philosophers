# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <asibille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:42 by asibille          #+#    #+#              #
#    Updated: 2022/05/10 10:33:38 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = a_philo.c cur_time.c end.c ft_print.c init_data.c next_and_prev.c sleep.c proper_exit.c utils/ft_atoi.c

MAIN = philo.c

OBJS = ${SRCS:.c=.o}

MAINOBJ = ${MAIN:.c=.o}

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS} ${MAINOBJ}
	${CC} ${CFLAGS} ${OBJS} ${MAINOBJ} -o ${NAME}
	
all: ${NAME}

clean:
	rm -f ${OBJS} ${MAINOBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re