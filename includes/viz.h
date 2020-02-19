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


# define IMG_H		1000
# define IMG_W		1000
# define MENU_H		100
# define MENU_W		100
# define HEIGHT		1000
# define WIDTH		1000
# define MAX_NUM	100

typedef struct		s_visual
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img1;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_visual;

t_visual			*init_ptr(void);


#endif
