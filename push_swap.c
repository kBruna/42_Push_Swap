/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/10/20 21:31:48 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_array(t_carray *stack, char *c)
{
	int	ctrl;

	ctrl = 0;
	ft_printf("\nStart\n");
	ft_printf("== Operation : %s ==\n", c);
	while (ctrl < stack->len)
	{
		ft_printf("Number : %d\n", stack->stack[(ctrl + stack->start) % \
			stack->max]);
		ctrl++;
	}
	ft_printf("End\n");
}

int	ft_sorted(t_carray *stack)
{
	int	temp;
	int	ctrl;

	ctrl = 0;
	temp = stack->stack[ctrl];
	ctrl++;
	while (ctrl < stack->len)
	{
		if (temp > stack->stack[ctrl])
			return (FALSE);
		temp = stack->stack[ctrl];
		ctrl++;
	}
	return (TRUE);
}

void ft_test(t_carray *stack, int argc)
{
	if (argc > 1)
	{
		ft_print_array(stack, "Before");
		ft_mer_sort(stack->stack, stack->start, stack->len-1);
		ft_print_array(stack, "After");
	}	
}

int	main(int argc, char **argv)
{
	int			*arg_a;
	int			check;
	int			len;
	t_carray	*stack_a;

	arg_a = NULL;
	len = 0;
	arg_a = ft_parsing(argc, argv, &len);
	if (len < 2)
		ft_error(arg_a, NULL, FALSE);
	check = ft_dup_check(arg_a, len);
	stack_a = ft_new_stack(arg_a, len, len);
	if (ft_sorted(stack_a))
		ft_error(stack_a->stack, stack_a, FALSE);
	ft_test(stack_a, len);
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
