/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vizualizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:06:01 by bsausage          #+#    #+#             */
/*   Updated: 2020/07/12 23:55:03 by Alkor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "viz.h"
#include "libft.h"
#include "get_next_line.h"

void	go_next(t_visual *ptr)
{
	do_operations(ptr->op_curr_list->op, &ptr->a, &ptr->b,
					ft_strlen(ptr->op_curr_list->op));
	ptr->op_curr_list = ptr->op_curr_list->next;
	ptr->prev = 1;
	if (!ptr->op_curr_list)
	{
		ptr->op_curr_list = ptr->op_end_list;
		ptr->next = 0;
	}
	drawing(ptr, ptr->a, ptr->b, ptr->len);
	if (!ptr->next)
	{
		if (check_sorted(&ptr->a, &ptr->b))
			draw_ok(ptr);
		else
			draw_ko(ptr);
	}
}

void	go_back(t_visual *ptr)
{
	if (ptr->next)
		ptr->op_curr_list = ptr->op_curr_list->prev;
	if (!ptr->op_curr_list)
	{
		ptr->op_curr_list = ptr->op_begin_list;
		ptr->prev = 0;
	}
	else
	{
		undo_operations(ptr->op_curr_list->op, &ptr->a, &ptr->b);
		ptr->next = 1;
	}
	drawing(ptr, ptr->a, ptr->b, ptr->len);
}

int		animation(t_visual *ptr)
{
	if (ptr->next && ptr->space == IS_PRESSED)
	{
		go_next(ptr);
		mlx_do_sync(ptr);
	}
	if (!ptr->next)
		ptr->space = NOT_PRESSED;
	return (0);
}

int		main(int argc, char **argv)
{
	t_visual		*ptr;

	ptr = NULL;
	if (argc == 1)
		return (0);
	if (!(ptr = init_ptr()))
		return (0);
	if (!(fill_stack(argc, argv, &ptr->a)))
		str_exit(&ptr->a, &ptr->b, 2);
	if (!(ptr->len = check_duplicate(ptr->a)))
		str_exit(&ptr->a, &ptr->b, 2);
	if (ptr->len == 1 || ptr->len > 500)
		str_exit(&ptr->a, &ptr->b, 3);
	if (!(get_operations(&ptr->op_begin_list, &ptr->op_end_list)))
		str_exit(&ptr->a, &ptr->b, 2);
	if (check_sorted(&ptr->a, &ptr->b) && !ptr->op_begin_list)
		str_exit(&ptr->a, &ptr->b, 4);
	get_index(ptr->a, ptr->len);
	ptr->op_curr_list = ptr->op_begin_list;
	init_mlx(ptr);
	drawing(ptr, ptr->a, ptr->b, ptr->len);
	draw_help(ptr);
	hooks(ptr);
	return (0);
}
