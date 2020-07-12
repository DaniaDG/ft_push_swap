/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/07/12 13:29:39 by Alkor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
		str_exit(&a, &b, 2);
	if (!(check_duplicate(a)))
		str_exit(&a, &b, 2);
	if (!(read_from_stdin(&a, &b, 0)))
		str_exit(&a, &b, 2);
	if (!(check_sorted(&a, &b)))
		str_exit(&a, &b, 0);
	else
		str_exit(&a, &b, 1);
	return (0);
}
