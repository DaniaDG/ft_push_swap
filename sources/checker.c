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

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;

	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
		str_exit(&a, &b, 2);
	if (!(check_duplicate(a)))
		str_exit(&a, &b, 2);
	if (!(read_from_stdin(&a, &b)))
		str_exit(&a, &b, 2);
	if (!(checker(&a, &b)))
		str_exit(&a, &b, 0);
	else
		str_exit(&a, &b, 1);
	return (0);
}

