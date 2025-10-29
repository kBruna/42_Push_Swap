/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:49 by buehara           #+#    #+#             */
/*   Updated: 2025/10/29 17:44:45 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ft_array_radix(int len)
{
	int **array;
	int	idx;

	idx = 0;
	array = malloc(10 * sizeof(int *));
	while (idx < 10)
	{
		array[idx] = malloc(sizeof(int) * len);
		idx++;
	}
	return (array);
}

void	ft_int_free(int **list, int len_list)
{
	int	i;

	if (list)
	{
		i = 0;
		while (len_list > 0)
		{
			free(list[len_list-1]);
			len_list--;
		}
		free(list);
	}
}

int	ft_copy_back(int *list, int **radix, int *rad, int idx, int len)
{
	int	ctrl;

	ctrl = len - 1;
	while ( idx >= 0 )
	{
		while ( rad[idx] > 0 )
		{
			list[ctrl] = radix[idx][rad[idx] - 1];
			rad[idx]--;
			ctrl--;
		}
		idx--;
	}
	return (idx);
}

void	ft_radix_sort(int *list, int len)
{
	int	**radix;
	int	exp;
	int	idx;
	int	rad[10];
	int i;

	exp = 1;
	idx = 0;
	i = ft_find_digits(list, len);
	radix = ft_array_radix(len);
	while ( i > 0 )
	{
		ft_memset(rad, 0, 10 * sizeof(int));
		while (idx < len)
		{
			radix[(list[idx] / exp) % 10][rad[(list[idx] / exp) % 10]] = list[idx];
			rad[(list[idx] / exp) % 10]++;
			idx++;
		}
		exp *= 10;
		ft_copy_back(list, radix, rad, idx, len);
		idx = 0;
		i--;
	}
	ft_int_free(radix,10);
}
