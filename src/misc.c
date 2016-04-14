/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_shit_for_now.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:18:21 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/15 15:18:31 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color					init_color(void)
{
	t_color			c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return (c);
}


t_ray					init_ray(int x, int y)
{
	t_ray			r;
//CAMERA STUFF X Y Z, like position and stuff.. or just position. 
	r.start.x = x;
	r.start.y = y;
	r.start.z = -2000;
	
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;	
	return (r);
}

int						closest(t_scene *sc, t_ray r, float *t)
{
	int				i;
	int				ret;

	i = 0;
	ret = -1;
	while (i < sc->ns)
	{
		if (intersection(&r, &sc->sphere[i], t))
			ret = i;
		i++;

	}
	return (ret);
}

void					bla(float coef, t_scene *sc, t_vec *n, t_vec *newStart)
{
	int					j;
	t_vec				dist;
	t_ray				lightRay;
	float				t;
	float				lambert;
	t_material			currentMat;

	j = -1;
	currentMat = sc->material[sc->sphere[sc->cs].material];
	while (++j < 3)
	{
		dist = vec_sub(&sc->light[j].pos, newStart);
		if (vec_dot(n, &dist) <= 0.0f)
			continue;
		t = sqrtf(vec_dot(&dist, &dist));
		if (t <= 0.0f)
			continue;
		
		lightRay.dir = vec_scal((1/t), &dist);
		lambert = vec_dot(&lightRay.dir, n) * coef; 
		sc->color.red += lambert * sc->light[j].color.red * currentMat.diffuse.red;
		sc->color.green += lambert * sc->light[j].color.green * currentMat.diffuse.green;
		sc->color.blue += lambert * sc->light[j].color.blue * currentMat.diffuse.blue;
	}
}