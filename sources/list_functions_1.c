/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:33:29 by Alkor             #+#    #+#             */
/*   Updated: 2020/07/12 13:33:33 by Alkor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*ft_create_elem(int data)
{
	t_stack		*tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	tmp->data = data;
	tmp->index = 0;
	tmp->up = NULL;
	tmp->down = NULL;
	return (tmp);
}

void			ft_push_down(t_stack **top, int data)
{
	add(top, ft_create_elem(data));
	*top = (*top)->down;
}

void			ft_push_up(t_stack **top, int data)
{
	add(top, ft_create_elem(data));
}

void			add(t_stack **top, t_stack *tmp)
{
	if (*top == NULL)
	{
		*top = tmp;
		(*top)->up = *top;
		(*top)->down = *top;
	}
	else if ((*top)->down == *top)
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

t_stack			*cut(t_stack **top)
{
	t_stack		*tmp;

	tmp = *top;
	if (*top == NULL)
		return (NULL);
	if ((*top)->down == *top)
		*top = NULL;
	else
	{
		(*top)->down->up = (*top)->up;
		*top = (*top)->down;
		(*top)->up->down = *top;
	}
	return (tmp);
}
