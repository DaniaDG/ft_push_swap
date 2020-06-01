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
#include "libft.h"
#include "get_next_line.h"

int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

int		key_release(int key, t_visual *ptr)
{
	if (key == 49)
		ptr->space = NOT_PRESSED;
	return (0);
}

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

int		key_press(int key, t_visual *ptr)
{
	if (key == 53)
		turn_off(ptr);
	if (key == 124 && ptr->next)
		go_next(ptr);
	if (key == 123 && ptr->prev)
		go_back(ptr);
	return (0);
}

void	hooks(t_visual *ptr)
{
	mlx_hook(ptr->win, 2, 0, key_press, ptr);
	//mlx_hook(ptr->win, 3, 0, key_release, ptr);
	//mlx_hook(ptr->win, 4, 0, mouse_press, ptr);
	//mlx_hook(ptr->win, 5, 0, mouse_release, ptr);
	//mlx_hook(ptr->win, 6, 0, mouse_move, ptr);
	mlx_hook(ptr->win, 17, 0, turn_off, ptr);
	mlx_loop(ptr->mlx);
}



static t_operations		*create_op_elem(char *data)
{
	t_operations		*tmp;

	if (!(tmp = (t_operations*)malloc(sizeof(t_operations))))
		return (NULL);
	if (!(tmp->op = ft_strdup(data)))
	{
		ft_memdel((void**)&tmp);
		return (NULL);
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

int		add_op_to_list(t_operations **begin_list, t_operations **end_list, char *data)
{
	t_operations	*tmp;
	
	if(!check_data(data))
		return (0);
	if (!(tmp = create_op_elem(data)))
	{
		free_op_list(begin_list);
		return (0);
	}
	if (*begin_list == NULL)
	{
		*begin_list = tmp;
		*end_list = *begin_list;
	}
	else
	{
		(*end_list)->next = tmp;
		tmp->prev = *end_list;
		*end_list = (*end_list)->next;
	}
	return (1);
}

int		get_operations(t_operations **op_begin_list, t_operations **op_end_list)
{
	char			*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(add_op_to_list(op_begin_list, op_end_list, line)))
		{
			free_op_list(op_begin_list);
			return (0);
		}
		ft_memdel((void**)&line);
	}
	return (1);
}

void	print_op_list(t_operations *op_list)
{
	t_operations	*tmp;

	tmp = op_list;
	while (tmp)
	{
		printf("%s\t", tmp->op);
		tmp = tmp->prev;
	}
}

int		main(int argc, char **argv)
{
	t_visual		*ptr = NULL;
	
	if (argc == 1)
		return (0);
	ptr = init_ptr();
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
