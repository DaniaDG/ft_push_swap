/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:06:02 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "viz.h"

t_visual	*ptr = NULL;

int		do_and_draw_operations(char *str, t_stack **a, t_stack **b)
{
	int		len;

	len = ft_strlen(str);
	if (len == 2)
		return(check_len2(str, a, b));
	if (len == 3)
		return(check_len3(str, a, b));
	draw_stack(ptr, *a, *b);
	return (0);
}

int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

void	hooks(t_visual *ptr)
{
	//mlx_hook(ptr->win, 2, 0, key_press, ptr);
	//mlx_hook(ptr->win, 4, 0, mouse_press, ptr);
	//mlx_hook(ptr->win, 5, 0, mouse_release, ptr);
	//mlx_hook(ptr->win, 6, 0, mouse_move, ptr);
	mlx_hook(ptr->win, 17, 0, turn_off, ptr);
	mlx_loop(ptr->mlx);
}

int		main(int argc, char **argv)
{
	t_stack		*a = NULL;
	t_stack		*b = NULL;
	//t_visual	*ptr = NULL;

	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &a)))
		str_exit(&a, &b, 2);
	if (!(check_duplicate(a)))
		str_exit(&a, &b, 2);
	ptr = init_ptr();
	if (!(read_from_stdin(&a, &b)))
		str_exit(&a, &b, 2);
	//if (!(checker(&a, &b)))
	//	str_exit(&a, &b, 0);
	//else
	//	str_exit(&a, &b, 1);
	hooks(ptr);
	return (0);
}
