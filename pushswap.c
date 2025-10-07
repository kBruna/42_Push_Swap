/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:57:02 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



int	main(int argc, char **argv)
{
	int	*arg;
	int	idx;
	int ctrl;

	if (argc >= 2)
	{
		idx = 0;
		arg = malloc(sizeof(int) * argc - 2);
		while (idx < argc - 1)
		{
			arg[idx] = atoi(argv[idx + 1]);
			idx++;
		}
		ctrl = 0;
		while (ctrl < idx)
		{
			ft_printf("Number : %d\n", arg[ctrl]);
			ctrl++;
		}
	}	
	return (0);
}
