/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:18:37 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:18:37 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "limits.h"

# define SA		"sa"
# define SB		"sb"
# define SS		"ss"
# define PA		"pa"
# define PB		"pb"
# define RA		"ra"
# define RB		"rb"
# define RR		"rr"
# define RRA	"rra"
# define RRB	"rrb"
# define RRR	"rrr"

typedef enum
{
	TRUE,
	FALSE
}	t_bool;

typedef struct			s_stack
{
	int					data;
	int					index;
	t_bool				status;
	struct s_stack		*up;
	struct s_stack		*down;
}						t_stack;



t_stack					*ft_create_elem(int data);
void					ft_push_down(t_stack **top, int data);
void					ft_push_up(t_stack **top, int data);
void					swap(t_stack **top);
void					push(t_stack **top1, t_stack **top2);
void					rotate(t_stack **top);
void					reverse_rotate(t_stack **top);
void					add(t_stack **top, t_stack *tmp);
t_stack					*del(t_stack **top);
void					free_stack(t_stack **top);
void					str_exit(t_stack **a, t_stack **b, int msg);

int						checker(t_stack **a, t_stack **b);
int						check_duplicate(t_stack *top);
int						read_from_stdin(t_stack **a, t_stack **b);
int						fill_stack(int argc, char **argv, t_stack **a);


int						get_status(t_stack *top);
void					print_stack(t_stack *a, t_stack *b);
t_stack					*get_markup(t_stack *top);
#endif
