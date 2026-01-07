/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:06:47 by buehara           #+#    #+#             */
/*   Updated: 2026/01/07 11:46:28 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

enum e_char
{
	SPACE = 32
};

enum e_stackPosition
{
	POS_UP,
	POS_KEEP,
	POS_DOWN,
	LEN_ADD = 1,
	LEN_MINUS = -1
};

enum e_maskr
{
	PZERO	= 64,
	RZERO	= 32,
	RSEC	= 16,
	SZERO	= 8,
	DOUBLE	= 4,
	AMASK	= 2,
	BMASK	= 1
};

enum e_maska
{
	PB,
	SA,
	RA,
	RRA,
	SB,
	RB,
	RRB,
	PA,
	T_MOVES
};

enum e_maskf
{
	SBCK = 9,
	SACK = 10,
	SSCK = 12,
	RBCK = 33,
	RACK = 34,
	RRCK = 36,
	RRBCK = 49,
	RRACK = 50,
	RRRCK = 52,
	PBCK = 65,
	PACK = 66
};

enum e_stack
{
	STB,
	STA,
	BITMASK = 0b1,
	TOPAMASK = 0b11111111,
	BOTAMASK = 0b11111110,
	BOTBMASK = 0b11111101,
	TOPBMASK = 0b11111100
};

typedef struct s_moves
{
	int		len;
	int		max;
	char	**moves;
}				t_moves;

typedef struct s_carray
{
	int		len;
	int		start;
	int		end;
	int		max;
	int		*stack;
}				t_carray;

typedef char	*(*t_mfunc)(t_carray *stack_a, t_carray *stack_b);

// ------------- atoi.c ---------------
int			ft_atoi_push(const char *nptr, char **list, int *arg);

// ------------- backtracking.c -------
int			bit_check(t_moves *m_list, int last, int bit_move);
int			ft_moves(t_moves *m_list, char *mov);
int			ft_log(int len, int base);
int			ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb);
t_moves		*ft_move_add(int llen);

// ------------- init.c ---------------
int			ft_find_idx(int *list, int len, int nbr);
int			*ft_copy_better(int *list, int len);
int			ft_check_args(int argc, char **argv);
void		ft_print_move(t_moves *list);

// ------------- move.c --------------
int			move_check(char *mov);
int			move_dub(int mov, t_moves *list, t_carray *sta, t_carray *stb);
int			move_limit(t_moves *list, t_carray *sta);
void		move_return(t_moves *list, t_carray *sta, t_carray *stb);
t_mfunc		func_list(int index);

// ------------- parsing.c -----------
int			ft_digit_check(char **str);
int			*ft_parsing(int argc, char **argv, int *len);
int			ft_dup_check(int *arg, int n);
void		ft_check_arg(char *str, int *null, int i);

// ------------- parsing_utils.c -----
int			ft_count_int(char **list);
char		*ft_rev_split(int n, char **args, char c);
void		ft_push_free(int *arg, t_carray *stack);
void		ft_error(void *arg, t_carray *stack, int check);
void		ft_str_free(char **list);

// ------------- push.c -------------
char		*ft_push_global(t_carray *src, t_carray *dest, char direction);
char		*push_a(t_carray *sta, t_carray *stb);
char		*push_b(t_carray *sta, t_carray *stb);
void		ft_push(t_carray *stack_a, t_carray *stack_b);

// ------------- push_swap.c --------
void		ft_push_swap(t_carray *stack);

// ------------- push_swap_base.c ----
void		ft_swap_base(t_carray *stk_a, int idx_a,
				t_carray *stk_b, int idx_b);
char		*ft_swap(t_carray *stack, char c);
char		*swap_a(t_carray *sta, t_carray *stb);
char		*swap_b(t_carray *sta, t_carray *stb);

// ------------- radix.c ------------
int			ft_find_digits(int *list, int len);
void		bit_shift(t_carray *sta);
void		ft_push_rad(t_carray *sta, t_carray *stb, char to_a, char to_b);

// ------------- rev_rotate.c -------
char		*ft_rev_rotate(t_carray *stack, char c);
char		*rev_rotate_a(t_carray *sta, t_carray *stb);
char		*rev_rotate_b(t_carray *sta, t_carray *stb);

// ------------- rotate.c -----------
char		*ft_rotate(t_carray *stack, char c);
char		*rotate_a(t_carray *sta, t_carray *stb);
char		*rotate_b(t_carray *sta, t_carray *stb);
void		ft_rotate_base(t_carray *stk, char direction);

// ------------- sort_utils.c ------
int			ft_bigger(int a, int b);
int			ft_smaller(int a, int b);
int			ft_find_xtreme(int *list, int len, int (*f) (int, int));
int			ft_sorted(t_carray *stack, int (*f)(int, int));
void		ft_swap_sort(int *a, int *b);

// ------------- stack.c -----------
int			ft_next(t_carray *stack, int index);
int			ft_before(t_carray *stack);
void		ft_att_tcarray(t_carray *stack, int start, int end, int len);
t_carray	*ft_new_stack(void *content, int len, int max);

#endif
