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

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;
	int			i = 1;

	if (argc == 1)
		return (0);
	//if (!(a = ft_create_elem(ft_atoi(argv[i++]))))
	//	return (0);
	while (i < argc)
		ft_push_down(&a, ft_atoi(argv[i++]));
	//print_stack(a);

	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	printf("*********************************\n");
	//print_stack(a);
	printf("*********************************\n");
	//print_stack(b);
	return (0);
}
