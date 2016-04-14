/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:44:10 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/14 15:44:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_discr(float b, float discr, float *t)
{
	float sqrtdiscr;
	float t0;
	float t1;

	sqrtdiscr = sqrtf(discr);
	t0 = (-b + sqrtdiscr) / (2);
	t1 = (-b - sqrtdiscr) / (2);
	if (t0 > t1)
		t0 = t1;
	if ((t0 > 0.001f) && (t0 < *t))
	{
		*t = t0;
		return (1);
	}
	return (0);
}

int			intersection(t_ray *r, t_sphere *s, float *t)
{
	float 	a;
	float	b;
	float	c;
	float	discr;
	t_vec	dist;

	 a = vec_dot(&r->dir, &r->dir);
	 dist = vec_sub(&r->start, &s->pos);
	 b = 2 * vec_dot(&r->dir, &dist);
	 c = vec_dot(&dist, &dist) - (s->r * s->r);
	 discr = b * b - 4 * a * c;
	if (discr < 0)
		return 0;
	else
		return (ft_discr(b, discr, t));
}