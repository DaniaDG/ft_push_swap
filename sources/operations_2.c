/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:16:07 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 13:16:08 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void		rotate_all(t_stack **a, t_stack **b, char *str)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (str)
		ft_putstr(str);
}

void		reverse_rotate_all(t_stack **a, t_stack **b, char *str)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	if (str)
		ft_putstr(str);
}

void		swap_all(t_stack **a, t_stack **b, char *str)
{
	swap(a, NULL);
	swap(b, NULL);
	if (str)
		ft_putstr(str);
}
