/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:00:40 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/15 13:00:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			get_num(char **s)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strnew(16);
	while(ft_isdigitand(**s))
	{
		tmp[i] = **s;
		(*s)++;
		i++;
	}
	(*s) += 2;
	return (ft_atof(tmp));
}
#include <stdio.h>
t_vec			get_position(int fd)
{
	char		*line;
	t_vec		vec;

	get_next_line(fd, &line);
	vec.x = get_num(&line);
	vec.y = get_num(&line);
	vec.z = get_num(&line);
	return (vec);
}

void			clear_scene(t_scene *sc)
{
	sc->material = NULL;
	sc->sphere = NULL;
	sc->light = NULL;
}

t_color			get_color(int fd)
{
	char		*line;
	t_color		color;

	get_next_line(fd, &line);
	color.red = get_num(&line);
	color.green = get_num(&line);
	color.blue = get_num(&line);
	return (color);
}

void			get_number_of(char *line, t_scene *sc)
{
		if (line == ft_strstr(line, "NM"))
			sc->nm = ft_atoi(line + 3);
		if (line == ft_strstr(line, "NS"))
			sc->ns = ft_atoi(line + 3);
		if (line == ft_strstr(line, "NL"))
			sc->nl = ft_atoi(line + 3);
}

