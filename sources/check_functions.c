/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"
#include "get_next_line.h"

int		check_digits(char *str)
{
	if (!ft_strlen(str))
		return (0);
	if (ft_strlen(str) == 1 && ft_isspace(*str))
		return (0);
	while (*str)
	{
		if (ft_strchr("+-0123456789", *str) == NULL &&
			!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int		fill_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	long	l;
	char	*end;
	char	*start;

	i = 0;
	while (++i < argc)
	{
		end = argv[i];
		if (!check_digits(argv[i]))
			return (0);
		while (*end)
		{
			start = end;
			l = ft_strtol(start, &end);
			if ((!ft_isspace(*end) && *end != '\0') || l > INT_MAX
				|| l < INT_MIN || *(end - 1) == '-' || *(end - 1) == '+')
				return (0);
			while (ft_isspace(*end))
				end++;
			ft_push_down(a, (int)l);
		}
	}
	return (1);
}

int		check_len2(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "sa"))
		swap(a, NULL);
	else if (ft_strequ(str, "sb"))
		swap(b, NULL);
	else if (ft_strequ(str, "ss"))
		swap_all(a, b, NULL);
	else if (ft_strequ(str, "pa"))
		push(b, a, NULL);
	else if (ft_strequ(str, "pb"))
		push(a, b, NULL);
	else if (ft_strequ(str, "ra"))
		rotate(a, NULL);
	else if (ft_strequ(str, "rb"))
		rotate(b, NULL);
	else if (ft_strequ(str, "rr"))
		rotate_all(a, b, NULL);
	else
		return (0);
	return (1);
}

int		check_len3(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "rra"))
		reverse_rotate(a, NULL);
	else if (ft_strequ(str, "rrb"))
		reverse_rotate(b, NULL);
	else if (ft_strequ(str, "rrr"))
		reverse_rotate_all(a, b, NULL);
	else
		return (0);
	return (1);
}

int		do_operations(char *str, t_stack **a, t_stack **b)
{
	int		len;

	len = ft_strlen(str);
	if (len == 2)
		return(check_len2(str, a, b));
	if (len == 3)
		return(check_len3(str, a, b));
	return (0);
}

int		read_from_stdin(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(do_operations(line, a, b)))
			return (0);
		ft_memdel((void**)&line);
	}
	return (1);
}

int		checker(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (*b)
		return (0);
	if (*a == NULL || (*a)->up == *a)
		return (1);
	tmp = (*a)->down;
	while (tmp != *a)
	{
		if (tmp->up->data > tmp->data)
			return (0);
		tmp = tmp->down;
	}
	return (1);
}

int		check_duplicate(t_stack *top)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	int			i;

	i = 1;
	if (top == NULL || top->down == top)
		return (1);
	tmp1 = top->down;
	while (tmp1 != top)
	{
		tmp2 = tmp1;
		while (tmp2 != top)
		{
			if (tmp2->data == tmp1->up->data)
				return (0);
			tmp2 = tmp2->down;
		}
		tmp1 = tmp1->down;
		i++;
	}
	return (i);
}

int		get_status(t_stack *top)
{
	t_stack	*tmp;
	int		max;
	int		i = 1;

	top->status = TRUE;
	max = top->data;
	tmp = top->down;
	//check 1 and 2 elemets
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


void	print_stack(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	if (!a)
		printf("a = NULL\n");
	else
	{
		tmp = a;
		printf("%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
		tmp = tmp->down;
		while (tmp != a)
		{
			printf("%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
			tmp = tmp->down;
		}
		printf("--\n");
		printf("a\n");
	}
	if (!b)
		printf("\tb = NULL\n");
	else
	{
		tmp = b;
		printf("\t%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
		tmp = tmp->down;
		while (tmp != b)
		{
				printf("\t%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
				tmp = tmp->down;
		}
		printf("\t--\n");
		printf("\tb\n");
	}
	printf("\n");
}


