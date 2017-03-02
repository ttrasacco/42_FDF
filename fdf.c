/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:08:04 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/02/23 14:08:07 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_call(int keycode, void *param)
{
	t_all	*tmp;

	tmp = (t_all *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126\
	|| keycode == 78 || keycode == 49 || keycode == 69 || keycode == 256)
		ft_draw_iso(tmp->p, tmp->s_mlx_ptr, tmp->s_win_ptr, keycode);
	return (0);
}

int			ft_round(double a)
{
	int r;

	r = (int)a;
	if (isnan(a))
		return (0);
	if (a >= 0)
		return (a - r >= 0.5 ? r + 1 : r);
	else
		return (a - r <= -0.5 ? r - 1 : r);
	return (r);
}

int			ft_get_color(t_point *p)
{
	int c;

	c = 0xFFFFFF;
	if (p->z <= -20)
		c = 0;
	if (p->z > -20 && p->z <= -15)
		c = 0x0A223F;
	if (p->z > -15 && p->z <= -10)
		c = 0x0F437E;
	if (p->z > -10 && p->z <= -5)
		c = 0x1461B8;
	if (p->z > -5 && p->z <= 0)
		c = 0x12B4C6;
	if (p->z > 0 && p->z <= 5)
		c = 0xF2D600;
	if (p->z > 5 && p->z <= 25)
		c = 0x40960B;
	if (p->z > 25 && p->z <= 35)
		c = 0x785D0C;
	if (p->z > 35)
		c = 0xEBEBEB;
	return (c);
}

t_all		*fill_t_all(t_point *p, void *mlx, void *win)
{
	t_all *s;

	if (!(s = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	s->p = p;
	s->s_mlx_ptr = mlx;
	s->s_win_ptr = win;
	return (s);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_point	*p;
	t_all	*s;

	if (argc > 1)
		p = ft_parsing_dir(argv[1]);
	else
		p = ft_parsing_dir("./");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	s = fill_t_all(p, mlx, win);
	ft_draw_iso(p, mlx, win, 0);
	mlx_hook(win, 2, 1, ft_key_call, s);
	mlx_loop(mlx);
	return (0);
}
