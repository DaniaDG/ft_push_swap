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

void	print_stack(t_stack *top)
{
	t_stack		*tmp;

	if (!top)
	{
		printf("NULL\n");
		return ;
	}
	tmp = top;
	printf("%d\n", tmp->data);
	tmp = tmp->down;
	while (tmp != top)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->down;
	}

	printf("\t%d\n", tmp->data);
	tmp = tmp->down;
	while (tmp != top)
	{
		printf("\t%d\n", tmp->data);
		tmp = tmp->down;
	}

	
	printf("\t\t%d\n", tmp->data);
	tmp = tmp->down;
	while (tmp != top)
	{
		printf("\t\t%d\n", tmp->data);
		tmp = tmp->down;
	}
}

int		check_digits(char *str)
{
	while (*str)
	{
		if (ft_strchr("+-0123456789\t ", *str) == NULL)
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
			ft_push_down(a, (int)l);
		}
	}
	return (1);
}

int		check_len2(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "sa"))
		swap(a);
	else if (ft_strequ(str, "sb"))
		swap(b);
	else if (ft_strequ(str, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (ft_strequ(str, "pa"))
		push(b, a);
	else if (ft_strequ(str, "pb"))
		push(a, b);
	else if (ft_strequ(str, "ra"))
		rotate(a);
	else if (ft_strequ(str, "rb"))
		rotate(b);
	else if (ft_strequ(str, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (0);
	return (1);
}

int		check_len3(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "rra"))
		reverse_rotate(a);
	else if (ft_strequ(str, "rrb"))
		reverse_rotate(b);
	else if (ft_strequ(str, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
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
	}
	return (1);
}

void	error_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	printf("Error\n");
	exit (1);
}

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;
	char		*end = NULL;

	printf("%ld\n", ft_strtol("123456+789", &end));
	printf("%s\n", end);
	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
		error_exit(&a, &b);
	if (!(check_duplicate(a)))
		error_exit(&a, &b);
	if (!(read_from_stdin(&a, &b)))
		error_exit(&a, &b);
	if (!(checker(&a, &b)))
		printf("\033[031mKO\n");
	else
		printf("\033[032mOK\n");
	write(1, "\033[0m", 6);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
