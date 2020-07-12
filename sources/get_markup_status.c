/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_markup_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			get_status(t_stack *top)
{
	t_stack	*tmp;
	int		max;
	int		i;

	i = 1;
	top->status = TRUE;
	max = top->data;
	tmp = top->down;
	while (tmp != top)
	{
		if (tmp->data > max)
		{
			tmp->status = TRUE;
			max = tmp->data;
			i++;
		}
		else
			tmp->status = FALSE;
		tmp = tmp->down;
	}
	return (i);
}

t_stack		*get_markup(t_stack *top)
{
	t_stack		*tmp;
	t_stack		*max;
	int			max_t;
	int			t;

	tmp = top->down;
	max = top;
	max_t = get_status(top);
	while (tmp != top)
	{
		if ((t = get_status(tmp)) > max_t)
		{
			max_t = t;
			max = tmp;
		}
		tmp = tmp->down;
	}
	return (max);
}
