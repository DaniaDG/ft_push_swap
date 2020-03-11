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
	return (a < b ? a : b);
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

t_stack		*find_place(t_stack *a, t_stack *b)
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
	//printf("b = %d, diff = %d, place = %d\n", b->index, diff, diff < 0 ? res->index : res->down->index);
	return (diff < 0 ? res : res->down);
}

t_stack	*choose_b(t_stack *a, t_stack *b, t_op_count *op_count)
{
	t_stack		*tmp_b;
	t_stack		*tmp_a;
	t_stack		*place;
	t_stack		*res;
	t_op_count	tmp;
	int			all;
	int			all_tmp;
	int			rb;
	int			rrb;

	tmp.ra = 0;
	tmp.rb = 0;
	tmp.rr = 0;
	tmp.rra = 0;
	tmp.rrb = 0;
	tmp.rrr = 0;
	
	tmp_b = b->down;
	place = find_place(a, b);
	//printf("place = %d\n", place->index);
	res = b;
	tmp_a = a;
	tmp.rra = len_stack(a);
	while (tmp_a != place)
	{
		tmp.ra++;
		tmp.rra--;
		tmp_a = tmp_a->down;
	}
	all = ft_min(tmp.ra, tmp.rra);
	tmp.rrb = len_stack(b);
	op_count->ra = tmp.ra < tmp.rra ? all : 0;
	op_count->rra = tmp.rra < tmp.ra ? all : 0;;
	op_count->rb = 0;
	op_count->rrb = 0;
	op_count->rr = 0;
	op_count->rrr = 0;
	//printf("111ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", op_count->ra, op_count->rra, op_count->rb, op_count->rrb, op_count->rr, op_count->rrr);
		
	while (tmp_b != b)
	{
		
		place = find_place(a, tmp_b);
		tmp.ra = 0;
		tmp.rra = len_stack(a);
		tmp_a = a;
		while (tmp_a != place)
		{
			tmp.ra++;
			tmp.rra--;
			tmp_a = tmp_a->down;
		}
		
		tmp.rb++;
		tmp.rrb--;
		rb = tmp.rb;
		rrb = tmp.rrb;
		all_tmp = count_num_of_operations(&tmp);
		//printf("ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", tmp.ra, tmp.rra, tmp.rb, tmp.rrb, tmp.rr, tmp.rrr);
		
		//all_tmp = ft_min(tmp.ra, tmp.rra);
		//all_tmp +=  ft_min(tmp.rb, tmp.rrb);
		if (all_tmp < all)
		{
			all = all_tmp;
			res = tmp_b;
			op_count->ra = tmp.ra;
			op_count->rra = tmp.rra;
			op_count->rr = tmp.rr;
			op_count->rb = tmp.rb;
			op_count->rrb = tmp.rrb;
			op_count->rrr = tmp.rrr;
			//printf("place = %d\n", place->index);
		}
		tmp.rb = rb;
		tmp.rrb = rrb;
		tmp_b = tmp_b->down;
	}
	//printf("ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", op_count->ra, op_count->rra, op_count->rb, op_count->rrb, op_count->rr, op_count->rrr);
		
	return (res);
}

void		find_first_elem(t_stack *a, t_op_count *op_count)
{
	t_stack		*tmp;

	tmp = a;
	op_count->ra = 0;
	op_count->rra = len_stack(a);
	while (tmp->index != 1)
	{
		op_count->ra++;
		op_count->rra--;
		tmp = tmp->down;
	}
}

void	sort(t_stack **a, t_stack **b, t_stack **markup)
{
	int		len;
	int		t;
	int		count;
	t_stack	*tmp_b;
	t_stack	*place;
	t_op_count	op_count;

	len = len_stack(*a);
	t = get_status(*markup);

	while (!all_true(*a))
	{
		while ((*a)->status == TRUE)
		{
			rotate(a);
			printf("ra\n");
		}
		while ((*a)->status == FALSE)
		{
			//print_stack(*a, *b);
			if ((*a)->status == FALSE)
			{
				push(a, b);
				printf("pb\n");
				//print_stack(*a, *b);
			}
		}
		//printf("choose b %d\n", (coose_b(*a, *b))->index);
	}
	print_stack(*a, *b);

	while (*b)
	{
		tmp_b = choose_b(*a, *b, &op_count);
		//printf("choose b %d\n", tmp_b->index);
		//printf("ra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d\n", op_count.ra, op_count.rra, op_count.rb, op_count.rrb, op_count.rr, op_count.rrr);
		
		while (op_count.rr > 0)
		{
			rotate(a);
			rotate(b);
			printf("rr\n");
			op_count.rr--;
		}
		while (op_count.rrr > 0)
		{
			reverse_rotate(a);
			reverse_rotate(b);
			printf("rrr\n");
			op_count.rrr--;
		}
		while (op_count.ra > 0)
		{
			rotate(a);
			printf("ra\n");
			op_count.ra--;
		}
		while (op_count.rb > 0)
		{
			rotate(b);
			printf("rb\n");
			op_count.rb--;
		}
		while (op_count.rra > 0)
		{
			reverse_rotate(a);
			printf("rra\n");
			op_count.rra--;
		}
		while (op_count.rrb > 0)
		{
			reverse_rotate(b);
			printf("rrb\n");
			op_count.rrb--;
		}
		push(b, a);
		printf("pa\n");
	}
	find_first_elem(*a, &op_count);
	if (op_count.ra < op_count.rra)
	{
		while (op_count.ra > 0)
		{
			rotate(a);
			op_count.ra--;
			printf("ra\n");
		}
	}
	else
	{
		while (op_count.rra > 0)
		{
			reverse_rotate(a);
			op_count.rra--;
			printf("rra\n");
		}
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
	//printf("len = %d\n", len);
	ps->markup = get_markup(ps->a);
	get_index(ps->a, len);
	get_status(ps->markup);
	//print_stack(ps->a, ps->b);
	sort(&ps->a, &ps->b, &ps->markup);
	//find_place(ps->a, ps->b);
	//rotate(&a);
	print_stack(ps->a, ps->b);

	return (0);
}

