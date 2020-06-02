/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:57:05 by bsausage          #+#    #+#             */
/*   Updated: 2020/03/11 11:57:06 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		a_cycle(t_stack *a, t_stack *position, t_op_count *tmp)
{
	t_stack		*tmp_a;

	tmp_a = a;
	tmp->ra = 0;
	tmp->rra = len_stack(a);
	while (tmp_a != position)
	{
		tmp->ra++;
		tmp->rra--;
		tmp_a = tmp_a->down;
	}
}

static void		get_res(t_stack **tmp_b, t_stack **res, t_op_count *tmp,
						t_op_count *op_count)
{
	t_op_count	tmp_tmp;

	tmp->rb++;
	tmp->rrb--;
	tmp_tmp = count_num_of_operations(tmp);
	if (tmp_tmp.all < op_count->all)
	{
		*res = *tmp_b;
		*op_count = assign_value(tmp_tmp);
	}
	*tmp_b = (*tmp_b)->down;
}

t_stack			*choose_b(t_stack *a, t_stack *b, t_op_count *op_count)
{
	t_stack		*tmp_b;
	t_stack		*position;
	t_stack		*res;
	t_op_count	tmp;

	tmp = assign_zero();
	position = find_position(a, b);
	res = b;
	a_cycle(a, position, &tmp);
	*op_count = count_num_of_operations(&tmp);
	tmp_b = b->down;
	tmp.rrb = len_stack(b);
	while (tmp_b != b)
	{
		position = find_position(a, tmp_b);
		a_cycle(a, position, &tmp);
		get_res(&tmp_b, &res, &tmp, op_count);
	}
	return (res);
}
