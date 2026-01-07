/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:55:37 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_carray *stack)
{
	t_moves		*list;
	t_carray	*st_b;
	int			*num;

	num = ft_calloc(sizeof(int), stack->len);
	list = ft_move_add(stack->len);
	st_b = ft_new_stack(num, 0, stack->len);
	if (stack->len < 6)
	{	
		ft_push_alg(list, stack, st_b);
		ft_print_move(list);
	}
	else
	{
		while (!ft_sorted(stack, ft_bigger))
			ft_push_rad(stack, st_b, 'a', 'b');
	}
	ft_push_free(st_b->stack, st_b);
	free(list->moves);
	free(list);
}
