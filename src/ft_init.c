/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:14:13 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/14 14:14:15 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_env				*init_env()
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		return NULL;
	e->f = malloc(sizeof(t_img));
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("hahah");
		return NULL;
	}
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Ray_Tracer_Basic")) == NULL)
	{
		ft_putendl("la");
		return NULL;
	}
	if ((e->f->img = mlx_new_image(e->mlx, WIN_X, WIN_Y)) == NULL)
{
	ft_putendl("li");
	return NULL;	
}
	ft_putendl("k");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size,
								&e->f->endian);
//	e->t = (double)time(NULL);
	return (e);
}

t_scene				*init_scene(char *av)
{
	int			fd;
	char		*line;
	t_scene		*sc;


	if (!(sc = malloc(sizeof(t_scene))))
		ft_error(NULL, NULL, "HAHAH");
		clear_scene(sc);
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error(NULL, "can't open", av);
	while (get_next_line(fd, &line))
	{
		get_number_of(line, sc);
		if (!(ft_strcmp(line, "MATERIAL:")))
			get_material(fd, sc);
		if (!(ft_strcmp(line, "SPHERE:")))
			get_sphere(fd, sc);
		if (!(ft_strcmp(line, "LIGHT:")))
			get_light(fd, sc);
	}
	return (sc);
}