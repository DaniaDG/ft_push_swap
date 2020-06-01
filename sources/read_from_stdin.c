/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin.c                                  :+:      :+:    :+:   */
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

int		read_from_stdin(t_stack **a, t_stack **b, int viz)
{
	char	*line;

	line = NULL;
	if (!viz)
	{
		while (get_next_line(0, &line) == 1)
		{
			if (!(do_operations(line, a, b, ft_strlen(line))))
				return (0);
			ft_memdel((void**)&line);
		}
	}
	return (1);
}
