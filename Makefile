# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 18:38:10 by buehara           #+#    #+#              #
#    Updated: 2026/01/06 20:02:00 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Program VARS
# =========================================================================== ||

NAME = push_swap
 
FLAGS = -Wall -Wextra -Werror -g3 -I.

CC = cc


#	Sources
# =========================================================================== ||

SRCS = 	atoi.c				\
		init.c				\
		push_swap.c			\
		push_swap_base.c	\
		stack.c				\
		rotate.c			\
		parsing.c			\
		parsing_utils.c		\
		push.c				\
		sort_utils.c		\
		rev_rotate.c		\
		radix.c				\
		move.c				\
		backtracking.c		\
		main.c

SRCS_DIR	= $(addprefix src/, $(SRCS))
OBJS_DIR		= obj
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT = libft/libft.a


#	Recipes
# ========================================================================== ||
all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $@


$(OBJS_DIR)/%.o : src/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\tCompiling -> $(notdir $<)"


$(LIBFT) :
	@$(MAKE) -sC libft/ all
	@echo "\n\tCompiling -> Libft"

#	Clean
# ========================================================================== ||
clean:
	@rm -fr $(OBJS_DIR)
	@$(MAKE) -sC libft/ $@
	@echo "\n\tDeleting OBJs"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC libft/ $@
	@echo "\tDeleting Files"


re : fclean all

#	.PHONY
# ========================================================================== ||
.PHONY : all clean fclean re
