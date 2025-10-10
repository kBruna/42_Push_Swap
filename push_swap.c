/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/10/10 16:40:33 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test(t_carray *stack, int argc)
{
	t_carray	*stack_b;

	ft_print_array(stack, ft_swap(stack, 'a'));
	ft_print_array(stack, ft_rotate(stack, 'a'));
	ft_print_array(stack, ft_rev_rotate(stack, 'a'));
	stack_b = ft_new_stack(NULL, 0, argc - 1);
	stack_b->stack = ft_calloc(sizeof(int), argc);
	ft_print_array(stack, ft_push(stack, stack_b, 'a'));
	ft_print_array(stack_b, "b");
	ft_print_array(stack, ft_push(stack, stack_b, 'b'));
	ft_print_array(stack_b, "b");
	ft_push_free(stack_b->stack, stack_b);
}

void	ft_print_array(t_carray *stack, char *c)
{
	int	ctrl;

	ctrl = 0;
	ft_printf("\nStart\n");
	ft_printf("== Operation : %s ==\n", c);
	while (ctrl < stack->len)
	{
		ft_printf("Number : %d\n", stack->stack[(ctrl + stack->start) % stack->max]);
		ctrl++;
	}
	ft_printf("End\n");
}

int	main(int argc, char **argv)
{
	int			*arg_a;
	int			ctrl;
	int			check;
	t_carray	*stack_a;

	arg_a = NULL;
	arg_a = ft_parsing(argc, argv);
	check = ft_dup_check(arg_a, argc - 1);
	stack_a = ft_new_stack(arg_a, argc - 1, argc - 1);
	ctrl = 0;
	while (ctrl < argc - 1)
	{
		ft_printf("Number : %d\n", stack_a->stack[ctrl]);
		ctrl++;
	}
	ft_test(stack_a, argc);
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
