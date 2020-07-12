/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:51:26 by Alkor             #+#    #+#             */
/*   Updated: 2020/07/12 13:03:20 by Alkor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"
#include "get_next_line.h"

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

static int				add_op_to_list(t_operations **begin_list,
						t_operations **end_list, char *data)
{
	t_operations	*tmp;

	if (!check_data(data))
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

int						get_operations(t_operations **op_begin_list,
						t_operations **op_end_list)
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
