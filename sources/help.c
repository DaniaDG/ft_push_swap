/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:15 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/14 16:08:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "viz.h"
#include "../ok.xpm"
#include "../ko.xpm"


void		draw_help(t_visual *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 10, 520, SILVER,
		"Use the arrows to sort     <=     =>");
}


void		draw_ok(t_visual *ptr)
{
	int		height = 0;
	int		width = 0;
	void	*ptr_img;

	ptr_img = mlx_xpm_file_to_image(ptr->mlx, "ok.xpm", &width, &height);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr_img, 500, 0);
}


void		draw_ko(t_visual *ptr)
{
	int		height = 0;
	int		width = 0;
	void	*ptr_img;

	ptr_img = mlx_xpm_file_to_image(ptr->mlx, "ko.xpm", &width, &height);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr_img, 600, 130);
}
