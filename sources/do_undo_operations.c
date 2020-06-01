/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_undo_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int		do_operations(char *str, t_stack **a, t_stack **b, int len)
{
	if (ft_strequ(str, "rra") && len == 3)
		reverse_rotate(a, NULL);
	else if (ft_strequ(str, "rrb") && len == 3)
		reverse_rotate(b, NULL);
	else if (ft_strequ(str, "rrr") && len == 3)
		reverse_rotate_all(a, b, NULL);
	else if (ft_strequ(str, "sa") && len == 2)
		swap(a, NULL);
	else if (ft_strequ(str, "sb") && len == 2)
		swap(b, NULL);
	else if (ft_strequ(str, "ss") && len == 2)
		swap_all(a, b, NULL);
	else if (ft_strequ(str, "pa") && len == 2)
		push(b, a, NULL);
	else if (ft_strequ(str, "pb") && len == 2)
		push(a, b, NULL);
	else if (ft_strequ(str, "ra") && len == 2)
		rotate(a, NULL);
	else if (ft_strequ(str, "rb") && len == 2)
		rotate(b, NULL);
	else if (ft_strequ(str, "rr") && len == 2)
		rotate_all(a, b, NULL);
	else
		return (0);
	return (1);
}

int		undo_operations(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "rra"))
		rotate(a, NULL);
	else if (ft_strequ(str, "rrb"))
		rotate(b, NULL);
	else if (ft_strequ(str, "rrr"))
		rotate_all(a, b, NULL);
	else if (ft_strequ(str, "sa"))
		swap(a, NULL);
	else if (ft_strequ(str, "sb"))
		swap(b, NULL);
	else if (ft_strequ(str, "ss"))
		swap_all(a, b, NULL);
	else if (ft_strequ(str, "pa"))
		push(a, b, NULL);
	else if (ft_strequ(str, "pb"))
		push(b, a, NULL);
	else if (ft_strequ(str, "ra"))
		reverse_rotate(a, NULL);
	else if (ft_strequ(str, "rb"))
		reverse_rotate(b, NULL);
	else if (ft_strequ(str, "rr"))
		reverse_rotate_all(a, b, NULL);
	return (0);
}
