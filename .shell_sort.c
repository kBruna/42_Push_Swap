/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shell_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:32:06 by buehara           #+#    #+#             */
/*   Updated: 2025/10/23 15:09:35 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_shell_sort(int *list, int len)
{
	int	out;
	int in;
	int temp;
	int gap;

	if (len <= 0)
		return ;
	gap = len / 2;
	while (gap > 0)
	{
		out	= gap;
		while (out < len)
		{
			in = out;
			temp = list[out];
			while (in >= gap && temp < list[in - gap])
			{
				list[in] = list[in - gap];
				in -= gap;
			}
			list[in] = temp;
			out++;
		}
		gap = gap/2;
	}
}
