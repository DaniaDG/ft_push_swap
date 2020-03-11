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

int		ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

int		ft_min(int a, int b)
{
	return (a <= b ? a : b);
}

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

void		find_first_elem(t_stack *a, t_op_count *op_count)
{
	t_stack		*tmp;

	*op_count = assign_zero();
	if (a->index == 1)
		return ;
	tmp = a;
	op_count->rra = len_stack(a);
	while (tmp->index != 1)
	{
		op_count->ra++;
		op_count->rra--;
		tmp = tmp->down;
	}
	if (op_count->ra <= op_count->rra)
		op_count->rra = 0;
	else
		op_count->ra = 0;
}

static void		check_swap_a(t_stack **a, t_stack *markup)
{
	//return ;
	if ((*a)->down->index > (*a)->up->index)
	{
		swap(a);
		write(1, "sa\n", 3);
		get_status(markup);
	}
}

static void		pre_sort(t_stack **a, t_stack **b, t_stack *markup)
{
	t_stack		*tmp_a;
	int			len;

	if (all_true(*a))
		return ;
	tmp_a = *a;
	len = len_stack(*a);
	while (len >= 0)
	{
		if ((*a)->down->status == FALSE)
			check_swap_a(a, markup);
		while ((*a)->status == TRUE && len >= 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
			len--;
		}
		while ((*a)->status == FALSE)
		{
			push(a, b);
			write(1, "pb\n", 3);
			len--;
		}
	}
}

static void		start_rotating(t_stack **a, t_stack **b, t_op_count *op_count)
{
	while (op_count->rr > 0)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
		op_count->rr--;
	}
	while (op_count->rrr > 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
		op_count->rrr--;
	}
	while (op_count->ra > 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		op_count->ra--;
	}
	while (op_count->rb > 0)
	{
		rotate(b);
		write(1, "rb\n", 3);
		op_count->rb--;
	}
	while (op_count->rra > 0)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		op_count->rra--;
	}
	while (op_count->rrb > 0)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
		op_count->rrb--;
	}
}

void	sort(t_stack **a, t_stack **b, t_stack **markup)
{
	int			len;
	int			t;
	t_stack		*tmp_b;
	t_op_count	op_count;

	len = len_stack(*a);
	t = get_status(*markup);
	pre_sort(a, b, *markup);
	while (*b)
	{
		op_count = assign_zero();
		tmp_b = choose_b(*a, *b, &op_count);
		start_rotating(a, b, &op_count);
		push(b, a);
		write(1, "pa\n", 3);
	}
	find_first_elem(*a, &op_count);
	start_rotating(a, b, &op_count);
}

int		sort_3(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->down->index == 3)
	{
		rotate(a);
		write(1, "ra\n", 3);
		swap(a);
		write(1, "sa\n", 3);
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->down->index == 1)
		{
			swap(a);
			write(1, "sa\n", 3);
		}
		else
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
	}
	else if ((*a)->index == 3)
	{
		if ((*a)->down->index == 1)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		else
		{
			swap(a);
			write(1, "sa\n", 3);
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}	
	}
	return (0);
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
	get_index(ps->a, len);
	ps->markup = get_markup(ps->a);
	if (len == 3)
		return (sort_3(&ps->a));
	get_status(ps->markup);
	sort(&ps->a, &ps->b, &ps->markup);
	//print_stack(ps->a, ps->b);
	return (0);
}

