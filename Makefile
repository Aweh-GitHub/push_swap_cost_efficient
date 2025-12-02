# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:38:46 by thantoni          #+#    #+#              #
#    Updated: 2025/12/02 09:19:36 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c							\
		ft_atoi.c						\
		ft_isnb.c						\
		ft_putstr.c						\
		ft_split.c						\
		ft_splitlen.c					\
		ft_strlen.c						\
		ft_strtoelems.c					\
		handler_args_initialization.c	\
		handler_sort.c					\
		sort_radix.c					\
		sort_two.c						\
		sort_three.c					\
		sort_four_five.c				\
		operation_push.c				\
		operation_rotate.c				\
		operation_swap.c				\
		operation_rev_rotate.c			\
		t_elem__utils.c					\
		t_stack__utils.c				

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re