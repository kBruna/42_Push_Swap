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

FLAGS = -Wall -Wextra -Werror -I.

CC = cc



SRCS = pushswap.c


OBJS = $(SRCS:.c=.o)


LIBFT = libft/libft.a


all: $(NAME)


$(NAME) : $(LIBFT) $(OBJS) 
	$(CC) $(OBJS) -Llibft -lft -o $@


%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft/ all


clean:
	rm -fr $(OBJS)
	$(MAKE) -C libft/ $@


fclean : clean
	rm -f $(NAME)
	$(MAKE) -C libft/ $@


re : fclean all

.PHONY : all bonus clean fclean re
