/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:01:11 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/02/23 18:45:41 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <dirent.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include "./libft/libftprintf.h"
# define SQR(a) (double)(a * a)
# define NO_PIXEL 1200
# define SW 500
# define PAINTABLE (p1->c == -1 || p2->c == -1)
# define IS_SPACE(c) (c == ' ' || c == '\n' || c == '\t' || c == '.')

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	int				c;
	struct s_point	*next;
}				t_point;

typedef struct	s_all
{
	t_point		*p;
	void		*s_mlx_ptr;
	void		*s_win_ptr;
}				t_all;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	c;
}				t_pixel;

/*
** get_next_line.c
*/

int				get_next_line(const int fd, char **line);

/*
** ft_parsing.c
*/

t_point			*ft_fill_coor(t_point *tmp, char **tab);
t_point			*ft_parsing(int fd);
int				ft_mini_ls(struct dirent *map, DIR *maps_dir, int *j);
t_point			*ft_parsing_dir(char *str);

/*
** Le reste.
*/

t_all			*fill_t_all(t_point *p, void *mlx, void *win);
void			ft_draw_iso(t_point *a, void *mlx, void *win, int keycode);
t_pixel			*ft_iso(t_point *p, int dx, int dy, int zoom);
void			ft_draw_line(t_pixel *p1, t_pixel *p2, void *mlx, void *win);
int				ft_get_color(t_point *p);
int				ft_round(double a);
int				ft_key_call(int keycode, void *param);
t_point			*get_link(t_point *start, double x, double y);

#endif
