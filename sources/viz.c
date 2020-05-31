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

/*t_visual	*ptr = NULL;

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
*/
int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

int		undo_operations(char *str, t_stack **a, t_stack **b)
{
	if (ft_strequ(str, "rra"))
		rotate(a, NULL);
	else if (ft_strequ(str, "rrb"))
		rotate(b, NULL);
	else if (ft_strequ(str, "rrr"))
		rotate_all(a, b, NULL);
	else if (ft_strequ(str, "sa"))
		swap(a, NULL);
	else if (ft_strequ(str, "sb"))
		swap(b, NULL);
	else if (ft_strequ(str, "ss"))
		swap_all(a, b, NULL);
	else if (ft_strequ(str, "pa"))
		push(a, b, NULL);
	else if (ft_strequ(str, "pb"))
		push(b, a, NULL);
	else if (ft_strequ(str, "ra"))
		reverse_rotate(a, NULL);
	else if (ft_strequ(str, "rb"))
		reverse_rotate(b, NULL);
	else if (ft_strequ(str, "rr"))
		reverse_rotate_all(a, b, NULL);
	return (0);
}

int		key_release(int key, t_visual *ptr)
{
	if (key == 49)
		ptr->space = NOT_PRESSED;
	return (0);
}

int		key_press(int key, t_visual *ptr)
{
	if (key == 124 && ptr->op_curr_list)
	{
		do_operations(ptr->op_curr_list->op, &ptr->a, &ptr->b);
		ptr->op_curr_list = ptr->op_curr_list->next;
	}
	drawing(ptr, ptr->a, ptr->b, ptr->len);
	return (0);
}

void	hooks(t_visual *ptr)
{
	mlx_hook(ptr->win, 2, 0, key_press, ptr);
	//mlx_hook(ptr->win, 3, 0, key_press, ptr);
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
	int				len;

	len = ft_strlen(data);
	if (len < 2 || len > 3)
		return (0);
	if (len == 2)
	{
		if (!(ft_strequ(data, "sa") || ft_strequ(data, "sb") || ft_strequ(data, "ss") ||
			ft_strequ(data, "pa") || ft_strequ(data, "pb") ||
			ft_strequ(data, "ra") || ft_strequ(data, "rb") || ft_strequ(data, "rr")))
			return (0);
	}
	if (len == 3)
	{
		if (!(ft_strequ(data, "rra") || ft_strequ(data, "rrb") || ft_strequ(data, "rrr")))
			return (0);
	}
	if (!(tmp = create_op_elem(data)))
	{
		//free_list;
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

void	free_op_list(t_operations **begin_list)
{
	t_operations	*tmp;

	//if (!(*begin_list))
	//	return ;
	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		ft_memdel((void**)&(tmp->op));
		ft_memdel((void**)&tmp);
	}
}

int		get_operations(t_operations **op_begin_list, t_operations **op_end_list)
{
	char			*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(add_op_to_list(op_begin_list, op_end_list, line)))
		{
			//free_list;
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
	if (!(check_duplicate(ptr->a)))
		str_exit(&ptr->a, &ptr->b, 2);
	if (!(get_operations(&ptr->op_begin_list, &ptr->op_end_list)))
		str_exit(&ptr->a, &ptr->b, 2);
	ptr->len = len_stack(ptr->a);
	get_index(ptr->a, ptr->len);
	ptr->op_curr_list = ptr->op_begin_list;
	init_mlx(ptr);
	drawing(ptr, ptr->a, ptr->b, ptr->len);
	//print_op_list(op_end_list);
	hooks(ptr);
	return (0);
}
