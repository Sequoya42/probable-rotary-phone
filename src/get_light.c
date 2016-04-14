/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:36:51 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/08 18:36:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_light_pos(int fd, char *line, t_scene *sc)
{
	int			i;

	i = 0;
	if (!(ft_strcmp(line, "position")))
	{
		while (i < sc->nl)
			sc->light[i++].pos = get_position(fd);
	}
}

void			get_light_intensity(int fd, char *line, t_scene *sc)
{
	int			i;

	i = 0;
	if (!(ft_strcmp(line, "color")))
	{
		while (i < sc->nl)
		{
			// get_next_line(fd, &line);
			sc->light[i++].color = get_color(fd);
		}
	}
}

void			get_light(int fd, t_scene *sc)
{
	char		*line;
	int			i;

	i = 0;
	if (!(sc->light = malloc(sizeof(t_light) * sc->nl)))
		return ;
	while(get_next_line(fd, &line))
	{
		get_light_pos(fd, line, sc);
		get_light_intensity(fd, line, sc);
			if (!(ft_strcmp(line, "###")))
			break;
	}
}