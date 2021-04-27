# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 13:44:38 by frtalleu          #+#    #+#              #
#    Updated: 2021/04/14 15:33:31 by frtalleu         ###   ########.fr        #
#                                                                             #
# **************************************************************************** #

SRCS = ./srcs/main.c ./srcs/time_utils.c ./srcs/manage_fork.c \
	   ./srcs/philo_routine.c ./srcs/utils.c ./srcs/free.c\

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	GCC = gcc
else
	GCC = clang-9
endif

.c.o:
	$(GCC) -c $< -o $(<:.c=.o)

NAME = philo_two

$(NAME): $(OBJS) $(OBJ)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

PHONY: clean fclean re
