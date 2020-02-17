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

#include "libft.h"
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

	i = 1;
	while (i < argc)
	{
		if (!check_digits(argv[i]))
			return (0);
		while (*(argv[i]))
		{
			ft_push_down(a, ft_atoi(argv[i]));
			while (*(argv[i]) == ' ' || *(argv[i]) == '\t')
				argv[i]++;
			if (*(argv[i]) == '-' || *(argv[i]) == '+')
				argv[i]++;
			while (*(argv[i]) != ' ' && *(argv[i]) != '\t' && *(argv[i]))
			{
				if (*(argv[i]) < '0' || *(argv[i]) > '9')
					return (0);
				argv[i]++;
			}
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;
	int			i = 1;

	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
	{
		free_stack(&a);
		printf("Error\n");
		return (0);
	}
	print_stack(a);
	swap(&a);
	printf("*********************************\n");
	print_stack(a);
	free_stack(&a);
	printf("*********************************\n");
	print_stack(a);
	return (0);
}
