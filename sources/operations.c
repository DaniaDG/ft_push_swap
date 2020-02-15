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

t_stack		*del(t_stack **top)
{
	t_stack		*tmp;

	tmp = *top;
	if (*top == NULL)
		return (NULL);
	if ((*top)->down == NULL || (*top)->down == *top)
		*top = NULL;
	else if ((*top)->down == *top)
	{
		*top = (*top)->down;
		(*top)->up = NULL;
		(*top)->down = NULL;
	}
	else
	{
		(*top)->down->up = (*top)->up;
		*top = (*top)->down;
		(*top)->up->down = *top;
	}
	return (tmp);
}

void		add(t_stack **top, t_stack *tmp)
{
	if (*top == NULL)
	{
		*top = tmp;
		(*top)->up = NULL;
		(*top)->down = NULL;
	}
	else if ((*top)->down == NULL)
	{
		(*top)->up = tmp;
		(*top)->down = tmp;
		(*top)->up->down = *top;
		(*top)->down->up = *top;
		*top = (*top)->up;
	}
	else
	{
		(*top)->up->down = tmp;
		(*top)->up->down->down = *top;
		(*top)->up->down->up = (*top)->up;
		(*top)->up = tmp;
		*top = (*top)->up;
	}
}
void		swap(t_stack **top)
{
	if (*top == NULL || (*top)->down == NULL)
		return ;
	if ((*top)->down == *top)
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
	if (*top1 ==  NULL || *top2 == NULL ||
		(*top1)->up == NULL || (*top2)->up == NULL || (*top1)->down == *top1)
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
