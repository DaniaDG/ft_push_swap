/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_num_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		count_num_of_operations(t_op_count *tmp)
{
	t_op_count	t[4];
	int			res[5];
	int		i = 0;

	tmp->rr = tmp->ra && tmp->rb ? ft_min(tmp->ra, tmp->rb) : 0;
	tmp->rrr = tmp->rra && tmp->rrb ? ft_min(tmp->rra, tmp->rrb) : 0;
	//printf("111ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", tmp->ra, tmp->rra, tmp->rb, tmp->rrb, tmp->rr, tmp->rrr);
		
	//case 0
	t[0].ra = tmp->ra - tmp->rr;
	t[0].rb = tmp->rb - tmp->rr;
	t[0].rr = tmp->rr;
	t[0].rra = 0;
	t[0].rrb = 0;
	t[0].rrr = 0;
	res[0] = t[0].ra + t[0].rb + t[0].rr; 
	//case 1
	t[1].ra = tmp->ra;
	t[1].rb = 0;
	t[1].rr = 0;
	t[1].rra = 0;
	t[1].rrb = tmp->rrb;
	t[1].rrr = 0;
	res[1] = t[1].ra + t[1].rrb; 
	//case 2
	t[2].ra = 0;
	t[2].rb = tmp->rb;
	t[2].rr = 0;
	t[2].rra = tmp->rra;
	t[2].rrb = 0;
	t[2].rrr = 0;
	res[2] = t[2].rb + t[2].rra; 
	//case 3
	t[3].ra = 0;
	t[3].rb = 0;
	t[3].rr = 0;
	t[3].rra = tmp->rra - tmp->rrr;
	t[3].rrb = tmp->rrb - tmp->rrr;
	t[3].rrr = tmp->rrr;
	res[3] = t[3].rra + t[3].rrb + t[3].rrr;

	res[4] = ft_min(ft_min(res[0], res[1]), ft_min(res[2], res[3]));

	while (i < 4)
	{
		if (res[4] == res[i])
		{
			tmp->ra = t[i].ra;
			tmp->rb = t[i].rb;
			tmp->rr = t[i].rr;
			tmp->rra = t[i].rra;
			tmp->rrb = t[i].rrb;
			tmp->rrr = t[i].rrr;
			break ;
		}
		i++;
	}
	//printf("111ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", tmp->ra, tmp->rra, tmp->rb, tmp->rrb, tmp->rr, tmp->rrr);
		
	return (res[4]);
}
