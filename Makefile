# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 18:38:10 by buehara           #+#    #+#              #
#    Updated: 2025/10/01 19:06:20 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap
FLAGS = -Wall -Wextra -Werror
CC = cc


LIBFT := libft/libft.a
INCLUDES := libft


SRCS = \

OBJS = $(SRCS:.c=.o)


AR = ar
ARFLAGS = rcs



all: $(NAME)


$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)


%.o : %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
