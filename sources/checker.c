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
	t_stack		*top1;
	t_stack		*top2;

	if (argc == 1)
		return (0);
	if (!(top1 = ft_create_elem(ft_atoi(argv[1]))))
		return (0);
	ft_push_down(&top1, ft_atoi(argv[2]));
	ft_push_down(&top1, ft_atoi(argv[3]));
	ft_push_down(&top1, ft_atoi(argv[4]));
	ft_push_down(&top1, ft_atoi(argv[5]));
	ft_push_up(&top1, ft_atoi(argv[6]));
	print_stack(top1);
	swap(&top1);
	printf("SWAP STACK1***********************************\n");
	print_stack(top1);
	rotate(&top1);
	printf("ROTATE STACK1***********************************\n");
	print_stack(top1);
	rotate(&top1);
	printf("ROTATE STACK1***********************************\n");
	print_stack(top1);
	rotate(&top1);
	printf("ROTATE STACK1***********************************\n");
	print_stack(top1);
	if (!(top2 = ft_create_elem(ft_atoi(argv[7]))))
		return (0);
	ft_push_down(&top2, ft_atoi(argv[8]));
	ft_push_down(&top2, ft_atoi(argv[9]));
	ft_push_down(&top2, ft_atoi(argv[10]));
	printf("***********************************\n");
	print_stack(top2);
	push(&top1, &top2);
	printf("PUSH FROM 1 TO 2***********************************\n");
	print_stack(top1);
	printf("***********************************\n");
	print_stack(top2);
	reverse_rotate(&top2);
	printf("REVERSE ROTATE STACK2***********************************\n");
	print_stack(top2);
	return (0);
}
