/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:27:12 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:50:22 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sort(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_bigger(int a, int b)
{
	if (a > b)
		return (TRUE);
	return (FALSE);
}

int	ft_smaller(int a, int b)
{
	if (a < b)
		return (TRUE);
	return (FALSE);
}

int	ft_find_xtreme(int *list, int len, int (*f) (int, int))
{
	int	result;
	int	idx;

	idx = 0;
	result = list[0];
	while (idx < len)
	{
		if (f(list[idx], result))
			result = list[idx];
		idx++;
	}
	return (result);
}

int	ft_sorted(t_carray *stack, int (*f)(int, int))
{
	int	temp;
	int	ctrl;
	int	start;

	if (stack->len == 0)
		return (TRUE);
	ctrl = 0;
	start = stack->start;
	temp = stack->stack[start];
	while (ctrl < stack->len - 1)
	{
		ctrl++;
		start = (ctrl + stack->start) % stack->max;
		if (f(temp, stack->stack[start]))
			return (FALSE);
		temp = stack->stack[start];
	}
	return (TRUE);
}
