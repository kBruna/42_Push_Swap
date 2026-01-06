/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_qsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:07:05 by buehara           #+#    #+#             */
/*   Updated: 2025/10/21 17:03:38 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rearrange(int *list, int pivot, int end)
{
	int	piv;

	piv = list[(end + pivot) / 2];
	while (pivot < end)
	{
		while (list[pivot] < piv)
			pivot++;
		while (list[end] > piv)
			end--;
		if (list[pivot] > list[end])
			ft_swap_sort(&list[pivot], &list[end]);
		else
			return (end);
		pivot++;
		end--;
	}
	return (end);	
}

void	ft_quick_sort(int *list, int pivot, int end)
{
	int	mid;

	if (end == pivot)
		return ;
	mid = ft_rearrange(list, pivot, end);
	ft_quick_sort(list, pivot, mid);
	ft_quick_sort(list, mid + 1, end);
}
