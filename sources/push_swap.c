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
#include "libft.h"

int		ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

int		ft_min(int a, int b)
{
	return (a <= b ? a : b);
}


int		all_true(t_stack *top)
{
	t_stack		*tmp;

	if (top->status == FALSE)
		return(0);
	tmp = top->down;
	while (tmp != top)
	{
		if (tmp->status == FALSE)
			return(0);
		tmp = tmp->down;
	}
	return (1);
}

t_stack		*find_position(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	t_stack		*res;
	int			diff;
	int			diff_tmp;

	tmp = a->down;
	res = a;
	diff = b->index - a->index;
	while (tmp != a)
	{
		diff_tmp = b->index - tmp->index;
		if (ft_abs(diff_tmp) < ft_abs(diff))
		{
			diff = diff_tmp;
			res = tmp;
		}
		tmp = tmp->down;
	}
	return (diff < 0 ? res : res->down);
}

t_op_count		assign_zero(void)
{
	t_op_count		t;

	t.ra = 0;
	t.rb = 0;
	t.rr = 0;
	t.rra = 0;
	t.rrb = 0;
	t.rrr = 0;
	t.all = 0;
	return (t);
}

t_op_count		assign_value(t_op_count tmp)
{
	t_op_count		t;

	t.all = tmp.all;
	t.ra = tmp.ra;
	t.rra = tmp.rra;
	t.rb = tmp.rb;
	t.rrb = tmp.rrb;
	t.rr = tmp.rr;
	t.rrr = tmp.rrr;
	return (t);
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
	if (checker(&ps->a, &ps->b))
		return (0);
	get_index(ps->a, len);
	if (!(short_sort(&ps->a, &ps->b, len)))
	{
		ps->markup = get_markup(ps->a);
		//get_status(ps->markup);
		//print_stack(ps->a, ps->b);
		sort(&ps->a, &ps->b, &ps->markup);
	}
	free_stack(&ps->a);
	free_stack(&ps->b);
	ft_memdel((void**)&ps);
	return (0);
}
