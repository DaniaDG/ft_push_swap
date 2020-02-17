/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:16:07 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 13:16:08 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		rotate(t_stack **top)
{
	if (*top == NULL || (*top)->down == NULL)
		return ;
	*top = (*top)->down;
}

void		reverse_rotate(t_stack **top)
{
	if (*top == NULL || (*top)->down == NULL)
		return ;
	*top = (*top)->up;
}

void		swap(t_stack **top)
{
	if (*top == NULL || (*top)->down == *top)
		return ;
	if ((*top)->down->down == *top)
	{
		*top = (*top)->down;
		return ;
	}
	(*top)->down->up = (*top)->up;
	(*top)->up->down = (*top)->down;
	(*top)->up = (*top)->down;
	(*top)->down = (*top)->down->down;
	(*top)->down->up = *top;
	(*top)->up->down = *top;
	*top = (*top)->up;
}

void		push(t_stack **top1, t_stack **top2)
{
	if (*top1 == NULL || *top2 == NULL || (*top1)->down == *top1)
	{
		add(top2, del(top1));
		return ;
	}
	(*top1)->up->down = (*top1)->down;
	(*top1)->down->up = (*top1)->up;
	(*top1)->up = (*top2)->up;
	(*top2)->up->down = *top1;
	*top1 = (*top1)->down;
	(*top2)->up->down->down = *top2;
	(*top2)->up = (*top2)->up->down;
	*top2 = (*top2)->up;
}
