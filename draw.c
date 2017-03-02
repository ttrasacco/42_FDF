/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tout.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:40:09 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/02/23 18:40:11 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*get_link(t_point *start, double x, double y)
{
	t_point	*p;

	p = start;
	while (p && (p->x != x || p->y != y))
		p = p->next;
	return (p);
}

void		ft_draw_line(t_pixel *p1, t_pixel *p2, void *mlx, void *win)
{
	double	x;
	double	y;
	double	hypothenuse;

	hypothenuse = sqrt(SQR((p2->x - p1->x)) + SQR((p2->y - p1->y)));
	x = (double)p1->x;
	y = (double)p1->y;
	x < -SW ? x = -SW : 0;
	x > SW ? x = SW : 0;
	y < -SW ? y = -SW : 0;
	y > SW ? x = SW : 0;
	if (((p1->x > SW || p1->x < -SW) || (p1->y > SW || p1->y < -SW)) &&\
	((p2->x > SW || p2->x < -SW) || (p2->y > SW || p2->y < -SW)))
		p1->c = 0x000000;
	else
	{
		while (((ft_round(x) != p2->x || ft_round(y) != p2->y)\
		&& (x <= SW && x >= -SW) && (y <= SW && y >= -SW)) && !PAINTABLE)
		{
			(ft_round(x) != p2->x) ? x += ((p2->x - p1->x) / hypothenuse) : 0;
			(ft_round(y) != p2->y) ? y += ((p2->y - p1->y) / hypothenuse) : 0;
			mlx_pixel_put(mlx, win, ft_round(x) + SW, ft_round(y) + SW, p1->c);
		}
	}
}

t_pixel		*ft_iso(t_point *p, int dx, int dy, int zoom)
{
	t_pixel		*pix;

	pix = (t_pixel*)malloc(sizeof(t_pixel));
	pix->x = (sqrt(2) / 2) * ((p->x + dx) - (p->y + dy)) * zoom;
	pix->y = -((sqrt((double)(2.0 / 3.0)) * (p->z))) - \
	(1 / sqrt(6)) * (p->x + dx + p->y + dy) * zoom;
	pix->c = p->c;
	p->z == NO_PIXEL ? pix->c = -1 : 0;
	return (pix);
}

void		do_pos(int *zoom, int *dx, int *dy, int keycode)
{
	*dx -= (keycode == 123) ? 5 : 0;
	*dy += (keycode == 123) ? 5 : 0;
	*dy -= (keycode == 125) ? 5 : 0;
	*dx -= (keycode == 125) ? 5 : 0;
	*dx += (keycode == 124) ? 5 : 0;
	*dy -= (keycode == 124) ? 5 : 0;
	*dy += (keycode == 126) ? 5 : 0;
	*dx += (keycode == 126) ? 5 : 0;
	*zoom -= (keycode == 78 || keycode == 49) && *zoom > 10 ? 2 : 0;
	*zoom += (keycode == 69 || keycode == 256) ? 2 : 0;
}

void		ft_draw_iso(t_point *a, void *mlx, void *win, int keycode)
{
	t_point		*b;
	static int	dx = 0;
	static int	dy = 0;
	static int	zoom = 20;

	do_pos(&zoom, &dx, &dy, keycode);
	mlx_clear_window(mlx, win);
	b = a;
	while (a)
	{
		if ((b = get_link(a, a->x, a->y + 1)))
			ft_draw_line(ft_iso(a, dx, dy, zoom),\
			ft_iso(b, dx, dy, zoom), mlx, win);
		if ((b = get_link(a, a->x + 1, a->y)))
			ft_draw_line(ft_iso(a, dx, dy, zoom),\
			ft_iso(b, dx, dy, zoom), mlx, win);
		a = a->next;
	}
}
