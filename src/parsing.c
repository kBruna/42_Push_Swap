/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:54:57 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:55:07 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg(char *str, int *null, int i)
{
	char	ch;

	ch = str[i];
	if (ft_isdigit(ch))
		*null = 1;
	if (!ft_isdigit(ch) && !ft_isspace(ch) && !ft_issignal(ch))
		ft_error(NULL, (t_carray *) NULL, TRUE);
	if (ft_issignal(ch) && ft_issignal(str[i + 1]))
		ft_error(NULL, (t_carray *) NULL, TRUE);
	if (ft_issignal(ch) && str[i + 1] == ' ')
		ft_error(NULL, (t_carray *) NULL, TRUE);
	if (ft_issignal(ch) && str[i - 1] && !ft_isspace(str[i - 1]))
		ft_error(NULL, (t_carray *) NULL, TRUE);
}

int	ft_digit_check(char **str)
{
	int		ct;
	int		i;
	int		null;

	ct = 1;
	while (str[ct])
	{
		i = 0;
		null = 0;
		while (str[ct][i])
		{
			ft_check_arg(str[ct], &null, i);
			i++;
		}
		if (!null)
			ft_error(NULL, (t_carray *) NULL, TRUE);
		ct++;
	}
	return (FALSE);
}

int	*ft_parsing(int argc, char **argv, int *len)
{
	int			*arg;
	char		*str;
	char		**list;
	long long	temp;

	ft_digit_check(argv);
	str = ft_rev_split(argc, argv, SPACE);
	list = ft_split(str, SPACE);
	free(str);
	arg = ft_calloc(sizeof(int), ft_count_int(list) + 1);
	if (arg == NULL)
		return (NULL);
	while (list[*len] != NULL)
	{
		temp = ft_atoi_push(list[*len], list, arg);
		if (temp > MAX_INT || temp < MIN_INT)
			break ;
		arg[*len] = temp;
		(*len)++;
	}
	ft_str_free(list);
	if (temp > MAX_INT || temp < MIN_INT)
		ft_error(arg, NULL, TRUE);
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
				ft_error(arg, (t_carray *) NULL, TRUE);
			idx++;
		}
		count++;
		ctrl = arg[count];
	}
	return (FALSE);
}
