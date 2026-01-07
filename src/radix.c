/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:39:05 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 11:42:15 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_digits(int *list, int len)
{
	int	max;
	int	count;

	max = ft_find_xtreme(list, len, ft_bigger);
	count = 0;
	while (max > 9)
	{
		max /= 10;
		count++;
	}
	count++;
	return (count);
}

void	bit_shift(t_carray *sta)
{
	int	idx;

	idx = 0;
	while (idx < sta->max)
	{
		sta->stack[idx] >>= 1;
		idx++;
	}
}

void	ft_push_rad(t_carray *sta, t_carray *stb, char to_a, char to_b)
{
	int	idx;

	idx = 0;
	while (idx < sta->max)
	{
		if (ft_sorted(sta, ft_bigger))
			break ;
		if ((sta->stack[sta->start] & BITMASK) == 0)
			ft_printf("%s\n", ft_push_global(sta, stb, to_b));
		else if ((sta->stack[sta->start] & BITMASK) == 1)
			ft_printf("%s\n", ft_rotate(sta, to_a));
		idx++;
	}
	while (stb->len > 0)
		ft_printf("%s\n", ft_push_global(stb, sta, to_a));
	bit_shift(sta);
}
