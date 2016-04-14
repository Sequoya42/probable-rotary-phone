/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:34:53 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/08 18:34:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_sphere_pos(int fd, char *line, t_scene *sc)
{
	int			i;

	i = 0;
	if (!(ft_strcmp(line, "position")))
	{
		while (i < sc->ns)
			sc->sphere[i++].pos = get_position(fd);
	}
}

void			get_sphere_rayon(int fd, char *line, t_scene *sc)
{
	int			i;

	i = 0;
	if (!(ft_strcmp(line , "rayon")))
	{
		while (i < sc->ns)
		{
		get_next_line(fd, &line);
		sc->sphere[i++].r = ft_atof(line);
		}
	}
}

void			get_sphere_material(int fd, char *line, t_scene *sc)
{
	int			i;

	i = 0;
	if (!(ft_strcmp(line, "material")))
	{
		while (i < sc->ns)
		{
			get_next_line(fd, &line);
			sc->sphere[i++].material = ft_atoi(line) - 1;
		}
	}
}

void			get_sphere(int fd, t_scene *sc)
{
	char		*line;
	int			i;

	i = 0;
	if (!(sc->sphere = malloc(sizeof(t_sphere) * sc->ns)))
		return ;
	while(get_next_line(fd, &line))
	{
		get_sphere_pos(fd, line, sc);
		get_sphere_rayon(fd, line, sc);
		get_sphere_material(fd, line, sc);
		if (!(ft_strcmp(line, "###")))
			break;
	}
}