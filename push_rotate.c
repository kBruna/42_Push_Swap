/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:03:45 by buehara           #+#    #+#             */
/*   Updated: 2025/10/15 16:47:08 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_base(t_carray *stack, char direction)
{
	if (direction == 'd')
	{
		ft_att_tcarray(stack, POS_UP, POS_KEEP, LEN_ADD);
		if (stack->len < stack->max)
			ft_swap_base(stack, stack->start, stack, stack->end);
		ft_att_tcarray(stack, POS_KEEP, POS_DOWN, LEN_MINUS);
	}
	else
	{
		ft_att_tcarray(stack, POS_KEEP, POS_DOWN, LEN_ADD);
		if (stack->len < stack->max)
			ft_swap_base(stack, stack->start, stack, stack->end);
		ft_att_tcarray(stack, POS_DOWN, POS_KEEP, LEN_MINUS);
	}
}

char	*ft_rotate(t_carray *stack, char c)
{
	char	*rotate;

	if (stack->len < 2)
		return (NULL);
	if (c == 'a')
		rotate = "ra";
	else
		rotate = "rb";
	ft_rotate_base(stack, 'u');
	return (rotate);
}

char	*ft_rev_rotate(t_carray *stack, char c)
{
	char	*rrotate;

	if (stack->len < 2)
		return (NULL);
	if (c == 'a')
		rrotate = "rra";
	else
		rrotate = "rrb";
	ft_rotate_base(stack, 'd');
	return (rrotate);
}
