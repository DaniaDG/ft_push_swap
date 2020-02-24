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

int		len_stack(t_stack *top)
{
	t_stack		*tmp;
	int			len;

	if (top == NULL)
		return (0);
	len = 1;
	tmp = top->down;
	while (tmp != top)
	{
		tmp = tmp->down;
		len++;
	}
	return (len);
}

t_stack	*coose_b(t_stack *a, t_stack *b)
{
	int		ra = 1;
	int		rb = 1;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;

	while (tmp_b != b->up)
	{
		ra++;
	}
	return (tmp_b);
}
void	get_max_min(t_stack *top, int *max, int *min)
{
	t_stack	*tmp;

	*max = top->index;
	*min = top->index;
	tmp = top->down;
	while (tmp != top)
	{
		if (tmp->index > *max)
			*max = tmp->index;
		else if (tmp->index < *min)
			*min = tmp->index;
		tmp = tmp->down;
	}
}

void	sort(t_stack **a, t_stack **b, t_stack **markup)
{
	int		len;
	int		t;
	int		t2;
	int		max;
	int		min;

	len = len_stack(*a);
	t = get_status(*markup);
	max = len;
	min = 1;
	while (!all_true(*a))
	{
		while ((*a)->status == TRUE)
			rotate(a);
		while ((*a)->status == FALSE)
		{
			print_stack(*a, *b);
			if ((*a)->status == FALSE)
			{
				push(a, b);
				print_stack(*a, *b);
			}
			get_max_min(*a, &max, &min);
			printf("\t\tmax = %d, min = %d\n", max, min);
		}
		//choose b
	}
}

int		main(int argc, char **argv)
{
	t_ps		*ps;
	int			len;

	if (argc == 1)
		return (0);
	ps = (t_ps *)malloc(sizeof(t_ps));
	ps->a = NULL;
	ps->b = NULL;
	if (!(fill_stack(argc, argv, &ps->a)))
		str_exit(&ps->a, &ps->b, 2);
	if (!(len = check_duplicate(ps->a)))
		str_exit(&ps->a, &ps->b, 2);
	printf("len = %d\n", len);
	ps->markup = get_markup(ps->a);
	get_index(ps->a, len);
	get_status(ps->markup);
	print_stack(ps->a, ps->b);
	sort(&ps->a, &ps->b, &ps->markup);
	//rotate(&a);
	//print_stack(a, b);

	return (0);
}

