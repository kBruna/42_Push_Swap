/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:06:56 by buehara           #+#    #+#             */
/*   Updated: 2025/10/10 15:07:23 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char	*ft_push(t_carray *stack_a, t_carray *stack_b, char direction)
{
	char	*push;

	if (direction == 'a')
	{
		push = "pb";
		ft_att_tcarray(stack_b, POS_UP, POS_KEEP, LEN_ADD);
		ft_swap_base(stack_a, stack_a->start, stack_b, stack_b->start);
		ft_att_tcarray(stack_a, POS_DOWN, POS_KEEP, LEN_MINUS);
	}
	else
	{
		push = "pa";
		ft_att_tcarray(stack_a, POS_UP, POS_KEEP, LEN_ADD);
		ft_swap_base(stack_b, stack_b->start, stack_a, stack_a->start);
		ft_att_tcarray(stack_b, POS_DOWN, POS_KEEP, LEN_MINUS);
	}
	return (push);
}
