/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:55:40 by buehara           #+#    #+#             */
/*   Updated: 2025/10/09 19:29:21 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_free(int *arg, t_carray *stack)
{
	if (arg)
		free(arg);
	if (stack)
		free(stack);
}

void	ft_error(void *arg, t_carray *stack)
{
	ft_push_free(arg, stack);
	ft_printf("Error\n");
	exit(TRUE);
}
