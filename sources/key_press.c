/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:57:09 by Alkor             #+#    #+#             */
/*   Updated: 2020/07/12 13:13:56 by Alkor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "viz.h"

int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

int		key_press(int key, t_visual *ptr)
{
	if (key == 53)
		turn_off(ptr);
	if (key == 124 && ptr->next)
		go_next(ptr);
	if (key == 123 && ptr->prev)
		go_back(ptr);
	if (key == 49)
	{
		ptr->space = ptr->space == NOT_PRESSED ? IS_PRESSED : NOT_PRESSED;
		mlx_loop_hook(ptr->mlx, &animation, ptr);
	}
	return (0);
}

void	hooks(t_visual *ptr)
{
	mlx_hook(ptr->win, 2, 0, key_press, ptr);
	mlx_hook(ptr->win, 17, 0, turn_off, ptr);
	mlx_loop(ptr->mlx);
}
