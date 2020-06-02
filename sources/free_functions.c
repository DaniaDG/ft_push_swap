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
//#include "viz.h"
#include "libft.h"

void	free_stack(t_stack **top)
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

void	free_op_list(t_operations **begin_list)
{
	t_operations	*tmp;

	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		ft_memdel((void**)&(tmp->op));
		ft_memdel((void**)&tmp);
	}
}

void	str_exit(t_stack **a, t_stack **b, int msg)
{
	free_stack(a);
	free_stack(b);
	if (msg == 0)
		write(1, "\033[031mKO\n", 10);
	if (msg == 1)
		write(1, "\033[032mOK\n", 10);
	if (msg == 2)
		write(1, "\033[033mERROR\n", 13);
	if (msg == 3)
		ft_putstr("stack length should be between 2 and 500\n");
	if (msg == 4)
		ft_putstr("the stack is already sorted\n");
	write(1, "\033[0m", 5);
	exit (1);
}
