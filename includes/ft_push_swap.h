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

# include "limits.h"
# include <stdlib.h>

# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"
# define PA		"pa\n"
# define PB		"pb\n"
# define RA		"ra\n"
# define RB		"rb\n"
# define RR		"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

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

typedef struct			s_ps
{
	t_stack				*a;
	t_stack				*b;
	t_stack				*markup;
}						t_ps;

typedef struct			s_op_count
{
	int					ra;
	int					rra;
	int					rr;
	int					rb;
	int					rrb;
	int					rrr;
	int					all;
}						t_op_count;


t_stack					*ft_create_elem(int data);
void					ft_push_down(t_stack **top, int data);
void					ft_push_up(t_stack **top, int data);
void					swap(t_stack **top, char *str);
void					push(t_stack **top1, t_stack **top2, char *str);
void					rotate(t_stack **top, char *str);
void					reverse_rotate(t_stack **top, char *str);
void					reverse_rotate_all(t_stack **a, t_stack **b, char *str);
void					rotate_all(t_stack **a, t_stack **b, char *str);
void					swap_all(t_stack **a, t_stack **b, char *str);
void					add(t_stack **top, t_stack *tmp);
t_stack					*cut(t_stack **top);
void					free_stack(t_stack **top);
void					str_exit(t_stack **a, t_stack **b, int msg);

int						checker(t_stack **a, t_stack **b);
int						check_duplicate(t_stack *top);
int						read_from_stdin(t_stack **a, t_stack **b, int viz);
int						fill_stack(int argc, char **argv, t_stack **a);

void					get_index(t_stack *top, int len);
int						get_status(t_stack *top);
int						all_true(t_stack *top);
void					print_stack(t_stack *a, t_stack *b);
t_stack					*get_markup(t_stack *top);

int						ft_min(int a, int b);
int						ft_abs(int a);
t_op_count				count_num_of_operations(t_op_count *tmp);
t_stack					*choose_b(t_stack *a, t_stack *b, t_op_count *op_count);
t_stack					*find_position(t_stack *a, t_stack *b);
t_op_count				assign_zero(void);
t_op_count				assign_value(t_op_count tmp);
int						len_stack(t_stack *top);
int						short_sort(t_stack **a, t_stack **b, int len);
void					sort(t_stack **a, t_stack **b, t_stack **markup);
void					sort_3(t_stack **a);
void					sort_4(t_stack **a, t_stack **b);
void					sort_5(t_stack **a, t_stack **b);
int						do_operations(char *str, t_stack **a, t_stack **b);

#endif
