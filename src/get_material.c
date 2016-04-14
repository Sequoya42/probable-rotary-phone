/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:40:35 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/08 18:40:38 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_material(int fd, t_scene *sc)
{
	char		*line;
	int			i;

	i = 0;
	if (!(sc->material = malloc(sizeof(t_material) * sc->nm)))
		return ;
		while (i < sc->nm)
		{
			sc->material[i].diffuse = get_color(fd);
			get_next_line(fd, &line);
			sc->material[i].reflection = ft_atof(line);
			i++;
		}
	// }
}