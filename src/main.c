/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:04:48 by rbaum             #+#    #+#             */
/*   Updated: 2016/02/24 12:14:40 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h> // REMOVe

void		print_scene(t_scene *sc)
{
	printf("nm : %d\n", sc->nm);
	printf("ns : %d\n", sc->ns);
	printf("nl : %d\n", sc->nl);
	int i = -1;
	printf("\n \t\tMATERIAL\n\n");
	while (++i < sc->nm)
	{
		printf("material %d : \n ", i);
		printf("color : %f \t %f \t %f \n", sc->material[i].diffuse.red, sc->material[i].diffuse.blue, sc->material[i].diffuse.green);
		printf("reflection %f\n", sc->material[i].reflection);
	}
	i = -1;
	printf("\n \t\t SPHERES \n\n");
	while (++i < sc->ns)
	{
		printf("sphere %d : \n", i);
		printf("position : %f \t %f \t %f \n", sc->sphere[i].pos.x, sc->sphere[i].pos.y, sc->sphere[i].pos.z);
		printf("rayon %f \n", sc->sphere[i].r);
		printf("material %d \n ", sc->sphere[i].material);
	}
	i = -1;
	printf("\n \t\t LIGHTS \n\n");
		while (++i < sc->nl)
	{
		printf("light %d : \n", i);
		printf("position : %f \t %f \t %f \n", sc->light[i].pos.x, sc->light[i].pos.y, sc->light[i].pos.z);
		printf("color : %f \t %f \t %f \n", sc->light[i].color.red, sc->light[i].color.blue, sc->light[i].color.green);
	}

}

int			main(int ac, char **av)
{
	t_env	*e;
	t_scene	*sc;

	if (ac != 2)
		return (ft_error("RT_V1 ", "needs to open a scene description", " av[1]"));
	e = init_env();
	sc = init_scene(av[1]);
	e->sc = sc;
	print_scene(sc);
	trace_img(e, sc);
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	 mlx_destroy_window(e->mlx, e->win);
	return (0);
}

void	ft_test(t_env *e)
{
	int x = 0;
	int y = 0;
	int c = try_color(212, 2, 4);
	while (x++ < WIN_X)
	{
		y = 0;
		while (y++ < WIN_Y)
			put_pixel(e->f, x, y, c);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == MK_ESC)
		exit(0);
	else if (keycode == MK_Z)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == MK_F)
	{
		trace_img(e, e->sc);
	}
	// 	MAX_ITER = (MAX_ITER < 8000) ? MAX_ITER * 2 : MAX_ITER;
	// else if (keycode == MK_MI)
	// 	MAX_ITER = (MAX_ITER > 2) ? MAX_ITER / 2 : MAX_ITER;
	// else if (keycode == MK_N)
	// 	e->color++;
	// else if (keycode == MK_B)
	// 	e->color = e->color == 0 ? 2 : 0;
	// else if (keycode == MK_R)
	// 	ft_reset(e);
	// else if (keycode == MK_C)
	// 	ft_change_frac(e);
//	move_coor(e, keycode);
//	ft_frequ(keycode, e);
	return (0);
}
