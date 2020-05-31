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

static double	percent(int start, int end, int current)
{
	double delta;

	delta = end - start;
	return ((delta == 0) ? 0.0 : (current / delta));
}

int				color(int current, int max, int color1, int color2)
{
	int		r;
	int		g;
	int		b;
	int		min;
	double	k;

	min = 0;
	k = percent(min, max, current);
	r = (int)(red(color1) + (red(color2) - red(color1)) * k);
	g = (int)(green(color1) + (green(color2) - green(color1)) * k);
	b = (int)(blue(color1) + (blue(color2) - blue(color1)) * k);
	return (rgb(r, g, b));
}

void		draw_stack(t_visual *ptr, t_stack *top, int len, int stack)
{
	t_stack		*tmp;
	int			x = 0;
	int			y = 500;
	int			k;
	int			step;
	int			max = len;

	k = len - 1;
	step = HEIGHT / len;
	len = len_stack(top);
	if (!top)
		return ;
	tmp = top->up;
	while (len-- > 0)
	{
		x = 500 * stack;
		while (x < 500 * (stack + 1))
		{
			y = step * (k + 1);
			while (y >= step * k)
			{
				put_pixel(ptr, x, y, color(tmp->index, max, BLUE, RED));
				y--;
			}
			x++;
		}
		k--;
		tmp = tmp->up;
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
