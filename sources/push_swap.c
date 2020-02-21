/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:50:57 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/21 09:50:59 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	get_index(t_stack *top, int len)
{
	int		i;
	t_stack	*max;
	t_stack	*min;
	t_stack	*tmp;

	i = len;
	tmp = top->down;
	min = top;
	while (tmp != top)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->down;
	}
	min->index = 1;
	while (len > 0)
	{
		max = min;
		tmp = top->down;
		if (top->data > max->data && !top->index)
			max = top;
		while (tmp != top)
		{
			if (tmp->data > max->data && !tmp->index)
				max = tmp;
			tmp = tmp->down;
		}
		max->index = len;
		len--;
	}
}

int		all_true(t_stack *top)
{
	t_stack		*tmp;

	tmp = top->down;
	while (tmp != top)
	{
		if (tmp->status == FALSE)
			return(0);
		tmp = tmp->down;
	}
	return (1);
}



void	sort(t_stack **a, t_stack **b, t_stack **markup)
{
	while (!all_true(*a))
	{
		while ((*a)->status == TRUE)
			rotate(a);
		while ((*a)->status == FALSE)
		{
			print_stack(*a, *b);
			if ((*a)->data > (*a)->down->data && (*a)->down->status == FALSE)
			{
				swap(a);
				get_status(*markup);
				print_stack(*a, *b);
			}
			if ((*a)->status == FALSE)
			{
				push(a, b);
				print_stack(*a, *b);
			}
		}
		//choose b
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;
	t_stack		*markup;
	int			len;

	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
		str_exit(&a, &b, 2);
	if (!(len = check_duplicate(a)))
		str_exit(&a, &b, 2);
	printf("len = %d\n", len);
	markup = get_markup(a);
	get_index(a, len);
	get_status(markup);
	print_stack(a, b);
	sort(&a, &b, &markup);
	//rotate(&a);
	//print_stack(a, b);

	return (0);
}

