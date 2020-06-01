/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:50:57 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/21 09:50:59 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		check_swap_a(t_stack **a, t_stack *markup)
{
	if ((*a)->down->index > (*a)->up->index &&
		(*a)->down->status == FALSE)
	{
		swap(a, SA);
		get_status(markup);
	}
}

static void		pre_sort(t_stack **a, t_stack **b, t_stack *markup)
{
	while (1)
	{
		check_swap_a(a, markup);
		if (all_true(*a))
			return ;
		while ((*a)->status == TRUE)
			rotate(a, RA);		
		while ((*a)->status == FALSE)
			push(a, b, PB);
	}
}

static void		find_first_elem(t_stack *a, t_op_count *op_count)
{
	t_stack		*tmp;

	*op_count = assign_zero();
	if (a->index == 1)
		return ;
	tmp = a;
	op_count->rra = len_stack(a);
	while (tmp->index != 1)
	{
		op_count->ra++;
		op_count->rra--;
		tmp = tmp->down;
	}
	if (op_count->ra <= op_count->rra)
		op_count->rra = 0;
	else
		op_count->ra = 0;
}

static void		start_rotating(t_stack **a, t_stack **b, t_op_count *op_count)
{
	while (op_count->rr-- > 0)
		rotate_all(a, b, RR);
	while (op_count->rrr-- > 0)
		reverse_rotate_all(a, b, RRR);
	while (op_count->ra-- > 0)
		rotate(a, RA);
	while (op_count->rb-- > 0)
		rotate(b, RB);
	while (op_count->rra-- > 0)
		reverse_rotate(a, RRA);
	while (op_count->rrb-- > 0)
		reverse_rotate(b, RRB);
}

void	sort(t_stack **a, t_stack **b, t_stack **markup)
{
	t_op_count	op_count;

	get_status(*markup);
	pre_sort(a, b, *markup);
	while (*b)
	{
		op_count = assign_zero();
		choose_b(*a, *b, &op_count);
		start_rotating(a, b, &op_count);
		push(b, a, PA);
	}
	find_first_elem(*a, &op_count);
	start_rotating(a, b, &op_count);
}
