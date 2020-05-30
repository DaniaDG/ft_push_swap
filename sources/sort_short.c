/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:50:57 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/21 09:50:59 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		short_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
	else
		return (0);
	return (1);
}

void		sort_3(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->down->index == 3)
	{
		swap(a, SA);
		rotate(a, RA);
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->down->index == 1)
			swap(a, SA);
		else
			reverse_rotate(a, RRA);
	}
	else if ((*a)->index == 3)
	{
		if ((*a)->down->index == 1)
			rotate(a, RA);
		else
		{
			swap(a, SA);
			reverse_rotate(a, RRA);
		}	
	}
}

void		sort_4(t_stack **a, t_stack **b)
{
	if ((*a)->index == 3)
		swap(a, SA);
	push(a, b, PB);
	(*a)->index = 0;
	(*a)->down->index = 0;
	(*a)->up->index = 0;
	get_index(*a, 3);
	sort_3(a);
	if ((*b)->index == 1)
		push(b, a, PA);
	else if ((*b)->index == 2)
	{
		push(b, a, PA);
		swap(a, SA);
	}
	else if ((*b)->index == 4)
	{
		push(b, a, PA);
		rotate(a, RA);
	}
}

void		sort_5(t_stack **a, t_stack **b)
{
	int		len;

	len = 0;
	while (len != 2)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
			push(a, b, PB);
		else
			rotate(a, RA);
		len = len_stack(*b);
	}
	(*a)->index = 0;
	(*a)->down->index = 0;
	(*a)->up->index = 0;
	get_index(*a, 3);
	sort_3(a);
	if ((*b)->index == 1)
		swap(b, SB);
	push(b, a, PA);
	push(b, a, PA);
}

