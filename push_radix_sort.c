/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:49 by buehara           #+#    #+#             */
/*   Updated: 2025/10/23 20:59:03 by buehara          ###   ########.fr       */
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

int	ft_find_digits(int *list, int len)
{
	int	max;
	int	count;

	max = ft_find_max(list, len);
	count = 0;
	while (max > 9)
	{
		max /= 10;
		count++;
	}
	count++;
	return (count);
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
	ft_memset(rad, 0, 10 * sizeof(int));
	while ( i > 0 )
	{
		while (idx < len)
		{
			rad[(list[idx] / exp) % 10]++;
			radix[(list[idx] / exp) % 10][rad[list[idx] / exp % 10]] = list[idx];
			idx++;
		}
		exp *= 10;
		while ( idx - 1 > 0 )
		{
			idx--;
			while (rad[idx] != 0)
			{
				list[idx] = radix[idx][rad[idx]];
				rad[idx]--;
			}
		}
		i--;
	}
	ft_int_free(radix,10);
}
