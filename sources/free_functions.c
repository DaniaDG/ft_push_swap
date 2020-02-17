/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:42:06 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/15 15:42:07 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		free_stack(t_stack **top)
{
	t_stack		*begin;

	if (*top == NULL)
		return ;
	if ((*top)->down == *top)
	{
		(*top)->up = NULL;
		(*top)->down = NULL;
		ft_memdel((void**)top);
	}
	else
	{
		begin = (*top)->up;
		(*top)->up->down = NULL;
		(*top)->up = NULL;
		while (*top != begin)
		{
			*top = (*top)->down;
			(*top)->up->down = NULL;
			ft_memdel((void**)&((*top)->up));
		}
	ft_memdel((void**)top);
	}
}
