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

int		check_sorted(t_stack **a, t_stack **b)
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

int		check_data(char *data)
{
	int				len;

	len = ft_strlen(data);
	if (len < 2 || len > 3)
		return (0);
	if (len == 2)
	{
		if (!(ft_strequ(data, "sa") || ft_strequ(data, "sb") ||
			ft_strequ(data, "ss") || ft_strequ(data, "pa") ||
			ft_strequ(data, "pb") || ft_strequ(data, "ra") ||
			ft_strequ(data, "rb") || ft_strequ(data, "rr")))
			return (0);
	}
	if (len == 3)
	{
		if (!(ft_strequ(data, "rra") || ft_strequ(data, "rrb") ||
			ft_strequ(data, "rrr")))
			return (0);
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
