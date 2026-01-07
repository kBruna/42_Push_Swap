/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:35 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:32:32 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*arg_a;
	int			check;
	int			len;
	t_carray	*stack_a;

	if (ft_check_args(argc, argv))
		ft_error(NULL, (t_carray *) NULL, TRUE);
	arg_a = NULL;
	len = 0;
	arg_a = ft_parsing(argc, argv, &len);
	if (len < 2)
		ft_error(arg_a, NULL, FALSE);
	check = ft_dup_check(arg_a, len);
	arg_a = ft_copy_better(arg_a, len);
	stack_a = ft_new_stack(arg_a, len, len);
	if (ft_sorted(stack_a, ft_bigger))
		ft_error(stack_a->stack, stack_a, FALSE);
	ft_push_swap(stack_a);
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
