/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:31:37 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:54:32 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_move(t_moves *list)
{
	int	i;

	i = 0;
	while (i < list->len)
	{
		ft_printf("%s\n", list->moves[i]);
		i++;
	}
}

int	ft_find_idx(int *list, int len, int nbr)
{
	int	idx;
	int	temp;

	idx = 0;
	temp = list[idx];
	while (idx < len && temp != nbr)
	{
		idx++;
		temp = list[idx];
	}
	return (idx);
}

int	*ft_copy_better(int *list, int len)
{
	int	*cpy;
	int	idx;
	int	max;
	int	count;
	int	min;

	cpy = ft_calloc(sizeof(int *), len);
	count = len;
	min = ft_find_xtreme(list, len, ft_smaller);
	if (min == MIN_INT)
	{
		idx = ft_find_idx(list, len, min);
		cpy[idx] = 0;
		count--;
	}
	while (0 < count)
	{
		max = ft_find_xtreme(list, len, ft_bigger);
		idx = ft_find_idx(list, len, max);
		cpy[idx] = count--;
		list[idx] = MIN_INT;
	}
	free(list);
	return (cpy);
}

int	ft_check_args(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (argv[index][0] == '\0')
			return (TRUE);
		index++;
	}
	return (FALSE);
}
