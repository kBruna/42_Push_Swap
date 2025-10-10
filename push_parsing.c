/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:54:57 by buehara           #+#    #+#             */
/*   Updated: 2025/10/09 19:10:31 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digit_check(char **argv)
{
	int	ctrl;
	int	idx;

	ctrl = 1;
	while (argv[ctrl])
	{
		idx = 0;
		while (argv[ctrl][idx])
		{
			if (!(ft_isdigit(argv[ctrl][idx])))
				ft_error(NULL, (t_carray *) NULL);
			idx++;
		}
		ctrl++;
	}
	return (0);
}

int	*ft_parsing(int argc, char **argv)
{
	int	idx;
	int	ctrl;	
	int	*arg;

	if (argc > 1)
	{
		idx = 1;
		ctrl = 0;
		ft_digit_check(argv);
		arg = ft_calloc(sizeof(int), argc);
		if (arg == NULL)
			return (NULL);
		while (idx < argc)
		{
			arg[ctrl++] = ft_atoi(argv[idx]);
			idx++;
		}
	}
	else
		exit(TRUE);
	return (arg);
}

int	ft_dup_check(int *arg, int n)
{
	int	ctrl;
	int	idx;
	int	count;

	count = 0;
	ctrl = arg[count];
	while (count < n)
	{
		idx = count + 1;
		while (idx < n)
		{
			if (ctrl == arg[idx])
				ft_error(arg, (t_carray *) NULL);
			idx++;
		}
		count++;
		ctrl = arg[count];
	}
	return (FALSE);
}
