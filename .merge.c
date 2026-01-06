/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:49:35 by buehara           #+#    #+#             */
/*   Updated: 2025/10/20 21:32:33 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mer_util(int *list, int start, int mid, int end)
{
	int	*temp;
	int	i;
	int	i_start;
	int	j_start;

	temp = ft_calloc((end - start) + 1, sizeof(int));
	i = 0;
	i_start = mid + 1;
	j_start = start;
	while (j_start <= mid && i_start <= end)
	{
		if (list[j_start] < list[i_start])
			temp[i++] = list[j_start++];
		else
			temp[i++] = list[i_start++];
	}
	while (j_start <= mid)
		temp[i++] = list[j_start++];
	while (i_start <= end)
		temp[i++] = list[i_start++];
	ft_memcpy(&list[start], temp, i * sizeof(int));
	free(temp);
}

void	ft_mer_sort(int *list, int start, int end)
{
	int	mid;

	if (start == end)
		return ;
	mid = (start + end) / 2;
	ft_mer_sort(list, start, mid);
	ft_mer_sort(list, mid + 1, end);
	ft_mer_util(list, start, mid, end);
}
