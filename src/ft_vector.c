/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:14:23 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/14 14:14:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			vec_sub(t_vec *v1, t_vec *v2)
{
	t_vec		r;

	r.x = v1->x - v2->x;
	r.y = v1->y - v2->y;
	r.z = v1->z - v2->z;
	return (r);
}

t_vec			vec_add(t_vec *v1, t_vec *v2)
{
	t_vec		r;

	r.x = v1->x + v2->x;
	r.y = v1->y + v2->y;
	r.z = v1->z + v2->z;
	return (r);
}

t_vec			vec_scal(float c, t_vec *v)
{
	t_vec		r;

	r.x = v->x * c;
	r.y = v->y * c;
	r.z = v->z * c;
	return (r);
}

float			vec_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
