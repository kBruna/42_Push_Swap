/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:06:47 by buehara           #+#    #+#             */
/*   Updated: 2025/10/10 16:34:11 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

enum e_stackPosition
{
	POS_UP,
	POS_KEEP,
	POS_DOWN,
	LEN_ADD = 1,
	LEN_MINUS = -1
};

typedef struct s_carray
{
	int	len;
	int	start;
	int	end;
	int	max;
	int	*stack;
}				t_carray;

// 		Test Functions
void		ft_test(t_carray *stack, int argc);
void		ft_print_array(t_carray *stack, char *c);


// 		Functions Utils
// ============================================================= ||

void		ft_error(void *arg, t_carray *stack);
void		ft_push_free(int *arg, t_carray *stack);

// 		Functions Stacks
// ============================================================= ||

void		ft_att_tcarray(t_carray *stack, int start, int end, int len);
t_carray	*ft_new_stack(void *content, int len, int max);

char		*ft_swap(t_carray *stack, char c);
char		*ft_push(t_carray *stack_a, t_carray *stack_b, char direction);
char		*ft_rotate(t_carray *stack, char c);
char		*ft_rev_rotate(t_carray *stack, char c);
void		ft_rotate_base(t_carray *stack, char direction);
void		ft_swap_base(t_carray *stk_a, int idx_a, \
						t_carray *stk_b, int idx_b);

// 		Functions Parsing
// ============================================================= ||

int			ft_digit_check(char **argv);
int			*ft_parsing(int argc, char **argv);
int			ft_dup_check(int *arg, int n);

#endif
