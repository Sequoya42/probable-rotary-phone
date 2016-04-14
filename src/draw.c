/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:16:19 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/14 14:16:19 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					put_pixel(t_img *e, int x, int y, int color)
{
	const unsigned int	bytes = e->bpp / 8;
	const unsigned int	p = x * bytes + y * e->line_size;
	size_t				i;

	i = 0;
	while (i < bytes)
	{
		e->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int						try_color(int red, int blue, int green)
{
    return ((red << 16) + (blue << 8) + green);
}

int					do_mid_shit(t_ray r, t_vec *newStart, t_vec *n, t_scene *sc)
{
	t_vec				scaled;
	float				temp;
	float				t;

	t = 20000.0f;
	sc->cs = -1;
	if ((sc->cs = closest(sc, r, &t)) == -1)
		return (-1);
	scaled = vec_scal(t, &r.dir);
	*newStart = vec_add(&r.start, &scaled);
	*n = vec_sub(newStart, &sc->sphere[sc->cs].pos);
	if ((temp = vec_dot(n, n)) == 0)
		return (-1);
	temp = 1.0f / sqrtf(temp);
	*n = vec_scal(temp, n);
	return (0);
}

void					do_shit(int x, int y, t_scene *sc)
{
	int					level;
	float				coef;
	t_ray				r;
	t_vec				newStart;
	t_vec				n;
	t_vec				tmp;
	float				reflect;

	level = 0;
	coef = 1.0;
	r = init_ray(x, y);
	while((coef > 0.0f) && (level < 15))
	{
		if ((do_mid_shit(r, &newStart, &n, sc)) == -1)
			break;
		bla(coef, sc, &n, &newStart);
		coef *= sc->material[sc->sphere[sc->cs].material].reflection;
		r.start = newStart;
		reflect = 2.0f * vec_dot(&r.dir, &n);
		tmp = vec_scal(reflect, &n);
		r.dir = vec_sub(&r.dir, &tmp);
		level++;
	}
}

int						trace_img(t_env *e, t_scene *sc)
{
	register int		x;
	register int		y;

	x = 0;
	y = 0;
	while (y++ < WIN_Y)
	{
		x = 0;
		while (x++ < WIN_Y)
		{
			sc->color = init_color();
			do_shit(x, y, sc);
			int tcol = try_color(RED, GREEN, BLUE);
			put_pixel(e->f, x, y, tcol);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (0);
}





