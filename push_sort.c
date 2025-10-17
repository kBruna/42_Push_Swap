/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:50:44 by buehara           #+#    #+#             */
/*   Updated: 2025/10/17 20:41:29 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(int *list, int len)
{
	int	in;
	int out;

	out = 0;
	while (out < len)
	{
		in = out + 1;
		while (in < len)
		{
			if (list[out] > list[in])
				ft_swap_sort(&list[out], &list[in]);
			in++;
		}
		out++;
	}
}


