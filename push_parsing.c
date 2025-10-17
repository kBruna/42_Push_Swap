/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:54:57 by buehara           #+#    #+#             */
/*   Updated: 2025/10/17 14:44:43 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digit_check(char **str)
{
	int	ct;
	int	i;

	ct = 1;
	while (str[ct])
	{
		i = 0;
		while (str[ct][i])
		{
			if (!ft_isdigit(str[ct][i]) && !ft_isspace(str[ct][i]) &&
						!(str[ct][i] == '-') && !(str[ct][i] == '+'))
				ft_error(NULL, (t_carray *) NULL, TRUE);
			i++;
		}
		ct++;
	}
	return (FALSE);
}

char	*ft_rev_split(int n, char **args, char c)
{
	char	*str;
	int		len;
	int		idx;

	idx = 1;
	len = 0;
	if (!c || !args)
		return (NULL);
	while (idx < n)
		len += ft_strlen(args[idx++]);
	str = ft_calloc((len + idx), sizeof(char));
	if (!str)
		return (NULL);
	idx = 1;
	len = 0;
	while (idx < n)
	{
		ft_strlcat(str, &c, ++len);
		len += ft_strlen(args[idx]);
		ft_strlcat(str, args[idx], len);
		idx++;
	}
	return (str);
}

int	ft_count_int(char **list)
{
	int	count;

	count = 0;
	while (list[count] != NULL)
	{
		count++;
	}
	return (count);
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
	arg = ft_calloc(sizeof(int), ft_count_int(list) + 1);
	if (arg == NULL)
		return (NULL);
	while (list[*len] != NULL)
	{
		temp = ft_atol(list[*len]);
		if (temp > MAX_INT || temp < MIN_INT)
			break ;
		arg[*len] = temp;
		(*len)++;
	}
	free(str);
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
