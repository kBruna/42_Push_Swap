/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_count_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:52:37 by buehara           #+#    #+#             */
/*   Updated: 2025/10/23 16:45:27 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(int *list, int len)
{
	int max;
	int	idx;

	idx = 0;
	max = list[0];
	while (idx < len)
	{
		if (list[idx] > max)
			max = list[idx];
		idx++;
	}
	return (max);
}

void	ft_counting_sort(int *list, int len)
{
	int max;
	int	*count;
	int	idx;
	int	idx_count;

	max = ft_find_max(list, len);
	count = malloc(sizeof(int) * max + 1);
	if (!count)
		return ;
	idx = 0;
	while (idx < len)
		count[list[idx++]]++;
	idx = 0;
	idx_count = 0;
	while (idx < len)
	{
		while (count[idx_count] > 0)
		{
			list[idx] = idx_count;
			count[idx_count]--;
			idx++;
		}
		idx_count++;
	}
}
