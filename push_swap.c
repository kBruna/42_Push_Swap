/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/10/30 20:44:19 by buehara          ###   ########.fr       */
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

void	ft_print_list(int *list, int len)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (len > i)
	{
		ft_printf("%d", list[i]);
		i++;
		if (i < len)
			ft_printf(",");
	}
	ft_printf("]\n");
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
	t_moves	*m_list;
	t_carray *st_b;
	int	*num;

	if (argc > 1)
	{
		m_list = malloc(sizeof(t_moves));
		num = ft_calloc(sizeof(int), argc);
		st_b = ft_new_stack(num, 0, argc);
		m_list->len = 0;
		m_list->moves = malloc(sizeof(char *) * 10);
		ft_print_array(stack, "Before");
		ft_moves_add(m_list, ft_push(stack, st_b, 'a'));
		ft_moves_add(m_list, ft_rotate(stack, 'a'));
		ft_moves_add(m_list, ft_push(stack, st_b, 'a'));
		ft_moves_add(m_list, ft_swap(stack, 'a'));
		ft_moves_add(m_list, ft_swap(st_b, 'b'));
		ft_moves_add(m_list, ft_push(stack, st_b, 'b'));
		ft_moves_add(m_list, ft_push(stack, st_b, 'a'));
		ft_moves_add(m_list, ft_rev_rotate(st_b, 'b'));
		ft_moves_add(m_list, ft_rev_rotate(stack, 'a'));
		ft_moves_add(m_list, ft_push(stack, stack, 'a'));
		for (int i = 0; i < m_list->len; i++)
			ft_printf("Move : %s\n", m_list->moves[i]);
		ft_print_array(stack, "After");
		free(m_list->moves);
		free(m_list);
		free(st_b);
	}	
}

void	ft_moves_add(t_moves *m_list, char *mov)
{
	char	*last_move;

	if (m_list->len == 0)
		last_move = NULL;
	else
		last_move = m_list->moves[m_list->len - 1];
	if (last_move && !ft_strncmp(last_move, "ss", 2)
			&&	!ft_strncmp(last_move, "rr", 2) && !ft_strncmp(last_move, "rrr", 3))
	{
		if (!ft_strncmp(last_move, "s", 1) && !ft_strncmp(mov, "s", 1))
			if(ft_strncmp(last_move, mov, 2) != 0)
				m_list->moves[m_list->len++ - 1] = "ss";
		if (!ft_strncmp(last_move, "r", 1) && !ft_strncmp(mov, "r", 1))
		{
			if(ft_strncmp(last_move, mov, 2) != 0)
				m_list->moves[m_list->len++ - 1] = "rr";
			else if (!ft_strncmp(last_move, "r", 1) && !ft_strncmp(mov, "r", 1))
				if (ft_strncmp(last_move, mov, 3) != 0)
					m_list->moves[m_list->len++ - 1] = "rrr";
		}
	}
	else
		m_list->moves[m_list->len++] = mov;
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
