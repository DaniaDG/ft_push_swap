/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:35:10 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:35:12 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*ft_create_elem(int data)
{
	t_stack		*tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	tmp->data = data;
	tmp->up = NULL;
	tmp->down = NULL;
	return(tmp);
}

void		ft_push_down(t_stack **top, int data)
{
	t_stack		*tmp;

	if (!(*top)->up && !(*top)->down)
	{
		(*top)->up = ft_create_elem(data);
		(*top)->down = (*top)->up;
		(*top)->up->up = *top;
		(*top)->up->down = *top;
	}
	else
	{
		tmp = (*top)->up;
		(*top)->up = ft_create_elem(data);
		tmp->down = (*top)->up;
		(*top)->up->up = tmp;
		(*top)->up->down = *top;
	}
}

void		ft_push_up(t_stack **top, int data)
{
	ft_push_down(top, data);
	*top = (*top)->up;
}
