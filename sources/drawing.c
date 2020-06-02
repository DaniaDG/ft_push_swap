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

#include "viz.h"
#include "ft_push_swap.h"

void		put_pixel(t_visual *ptr, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
	{
		i = (x * ptr->bits_per_pixel / 8) + (y * ptr->size_line);
		ptr->data_addr[i] = blue(color);
		ptr->data_addr[++i] = green(color);
		ptr->data_addr[++i] = red(color);
	}
}

void		draw_stack(t_visual *ptr, t_stack *top, int len, int stack)
{
	int			x;
	int			y;
	int			k;
	int			step;
	int			n;

	k = len - 1;
	step = (HEIGHT - 50) / len;
	n = len_stack(top);
	if (!top)
		return ;
	while (n-- > 0)
	{
		x = (WIDTH / 2) * stack;
		while (x++ < (WIDTH / 2) * (stack + 1))
		{
			y = step * (k + 1);
			while (y-- >= step * k)
				put_pixel(ptr, x - 1, y + 1, color(top->up->index, len,
														SILVER, BLUE));
		}
		k--;
		top = top->up;
	}
}

int			drawing(t_visual *ptr, t_stack *a, t_stack *b, int len)
{
	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	draw_stack(ptr, a, len, 0);
	draw_stack(ptr, b, len, 1);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}
