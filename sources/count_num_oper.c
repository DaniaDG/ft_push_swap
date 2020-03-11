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

static t_op_count		case_0(t_op_count *tmp,  int rr, int rrr)
{
	t_op_count		t;

	rrr = 0;
	t.ra = tmp->ra - rr;
	t.rb = tmp->rb - rr;
	t.rr = rr;
	t.rra = 0;
	t.rrb = 0;
	t.rrr = 0;
	t.all = t.ra + t.rb + t.rr;
	return (t);
}

static t_op_count		case_1(t_op_count *tmp,  int rr, int rrr)
{
	t_op_count		t;

	rr = 0;
	rrr = 0;
	t.ra = tmp->ra;
	t.rb = 0;
	t.rr = 0;
	t.rra = 0;
	t.rrb = tmp->rrb;
	t.rrr = 0;
	t.all = t.ra + t.rrb; 
	return (t);
}

static t_op_count		case_2(t_op_count *tmp,  int rr, int rrr)
{
	t_op_count		t;

	rr = 0;
	rrr = 0;
	t.ra = 0;
	t.rb = tmp->rb;
	t.rr = 0;
	t.rra = tmp->rra;
	t.rrb = 0;
	t.rrr = 0;
	t.all = t.rb + t.rra; 
	return (t);
}

static t_op_count		case_3(t_op_count *tmp,  int rr, int rrr)
{
	t_op_count		t;

	rr = 0;
	t.ra = 0;
	t.rb = 0;
	t.rr = 0;
	t.rra = tmp->rra - rrr;
	t.rrb = tmp->rrb - rrr;
	t.rrr = rrr;
	t.all = t.rra + t.rrb + t.rrr;
	return (t);
}

t_op_count				count_num_of_operations(t_op_count *tmp)
{
	t_op_count	t[4];
	int			rr;
	int			rrr;
	int			i;
	int 		res;

	rr = tmp->ra && tmp->rb ? ft_min(tmp->ra, tmp->rb) : 0;
	rrr = tmp->rra && tmp->rrb ? ft_min(tmp->rra, tmp->rrb) : 0;	
	t[0] = case_0(tmp, rr, rrr);
	t[1] = case_1(tmp, rr, rrr);
	t[2] = case_2(tmp, rr, rrr);
	t[3] = case_3(tmp, rr, rrr);
	res = ft_min(ft_min(t[0].all, t[1].all), ft_min(t[2].all, t[3].all));
	i = 0;
	while (i < 4)
	{
		if (res == t[i].all)
			break ;
		i++;
	}
	return (t[i]);
}
