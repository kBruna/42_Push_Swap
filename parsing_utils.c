/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:55:40 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:38:47 by buehara          ###   ########.fr       */
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

void	ft_error(void *arg, t_carray *stack, int check)
{
	ft_push_free(arg, stack);
	if (check)
		write(2, "Error\n", 6);
	exit(TRUE);
}

void	ft_str_free(char **list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
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
