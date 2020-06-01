/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

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
