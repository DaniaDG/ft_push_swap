/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:18:37 by bsausage          #+#    #+#             */
/*   Updated: 2020/02/12 09:18:37 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "ft_push_swap.h"


# define IMG_H		1000
# define IMG_W		1000

# define MENU_H		100
# define MENU_W		100

# define HEIGHT		1000
# define WIDTH		1000
# define MAX_NUM	100

# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define YELLOW			0xFFFDAC
# define GREY			0x555555
# define PINK			0xFF4DC4
# define SILVER			0xCCCCCC

# define WHITE			0xFFFFFF
# define BLACK			0x000000


typedef struct		s_image
{
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_visual
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;


	t_image			*image;
	
}					t_visual;

typedef struct			s_operations
{
	char				*str;
	struct s_operations	*next;
	struct s_operations	*prev;
}						t_operations;

t_visual			*init_ptr(void);
int					red(int rgb);
int					green(int rgb);
int					blue(int rgb);
int					rgb(int r, int g, int b);
int		check_len2(char *str, t_stack **a, t_stack **b);
int		check_len3(char *str, t_stack **a, t_stack **b);
int			draw_stack(t_visual *ptr, t_stack *a, t_stack *b);

#endif
