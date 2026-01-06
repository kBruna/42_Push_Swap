/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:43:33 by buehara           #+#    #+#             */
/*   Updated: 2026/01/06 17:54:20 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_check(t_moves *m_list, int last, int bit_move)
{
	if (last && (bit_move ^ last) == 3)
	{
		if ((bit_move ^ RZERO) < bit_move)
		{
			if ((bit_move ^ RSEC) < bit_move)
			{
				m_list->moves[m_list->len - 1] = "rrr";
				return (TRUE);
			}
			else
			{
				m_list->moves[m_list->len - 1] = "rr";
				return (TRUE);
			}
		}	
		if ((bit_move ^ SZERO) < bit_move)
		{
			m_list->moves[m_list->len - 1] = "ss";
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_moves(t_moves *m_list, char *mov)
{
	int	last;
	int	bit_move;

	if (m_list->len == m_list->max - 1 || mov == NULL)
		return (TRUE);
	if (m_list->len == 0)
		last = 0;
	else
		last = move_check(m_list->moves[m_list->len - 1]);
	bit_move = move_check(mov);
	if (bit_check(m_list, last, bit_move))
		return (TRUE);
	if (!last || last == move_check(m_list->moves[m_list->len - 1]))
		m_list->moves[m_list->len++] = mov;
	return (FALSE);
}

int	ft_log(int len, int base)
{
	int	log_base;
	int	result;
	int	log;

	log = 0;
	log_base = base;
	result = len;
	if (len < 10)
	{
		log = 2;
		return (log);
	}
	while (result > log_base)
	{
		result = result / log_base;
		log++;
	}
	log++;
	return (log);
}

t_moves	*ft_move_add(int llen)
{
	t_moves	*list;
	int		max;

	if (llen < 4)
		max = llen + 1;
	else
		max = llen * (1.12 * ft_log(llen, 2)) + 1;
	list = malloc(sizeof(t_moves));
	list->len = 0;
	list->max = max;
	list->moves = ft_calloc(sizeof(char *), max);
	return (list);
}

int	ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb)
{
	int		idx;
	char	*mov;
	t_mfunc	ft;

	if (sta->len == sta->max && ft_sorted(sta, ft_bigger) && stb->len == 0)
		return (TRUE);
	if (list->len == list->max - 1 || move_limit(list, sta))
		return (FALSE);
	idx = -1;
	while (idx++ < T_MOVES - 1 && (!ft_sorted(sta, ft_bigger) || stb->len != 0))
	{
		if (!move_dub(idx, list, sta, stb))
			continue ;
		ft = func_list(idx);
		mov = ft(sta, stb);
		if (mov == NULL)
			continue ;
		if (ft_moves(list, mov))
			return (FALSE);
		if (ft_push_alg(list, sta, stb))
			return (TRUE);
		move_return(list, sta, stb);
	}
	return (FALSE);
}
