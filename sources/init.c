/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "viz.h"

static void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	init_mlx(t_visual *ptr)
{
	if (!(ptr->mlx = mlx_init()))
		error("mlx init error");
	if (!(ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "Push swap vizualizer by bsausage")))
		error("windows init error");
	if (!(ptr->img = mlx_new_image(ptr->mlx, IMG_W, IMG_H)))
		error("image init error");
	ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bits_per_pixel),
										&(ptr->size_line), &(ptr->endian));
}

t_visual		*init_ptr(void)
{
	t_visual	*ptr;

	if (!(ptr = (t_visual *)malloc(sizeof(t_visual))))
		error("init error");
	ptr->a = NULL;
	ptr->b = NULL;
	ptr->op_begin_list = NULL;
	ptr->op_end_list = NULL;
	ptr->op_curr_list = NULL;
	ptr->space = NOT_PRESSED;
	ptr->next = 1;
	ptr->prev = 0;
	
	//init_mlx(ptr);	
	return (ptr);
}
