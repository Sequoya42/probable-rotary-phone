/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:16:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/02/24 12:16:40 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "misc.h"

typedef struct			s_vec
{
	float				x;
	float				y;
	float				z;
}						t_vec;

typedef struct			s_ray
{
	t_vec				start;
	t_vec				dir;
}						t_ray;

typedef struct			s_color
{
	float				red;
	float				blue;
	float				green;
}						t_color;

typedef struct 			s_material
{
	t_color				diffuse;
	float				reflection;
}						t_material;


typedef struct			s_sphere
{
	t_vec				pos;
	float				r;
	int					material;
}						t_sphere;
		
typedef struct			s_light
{
	t_vec				pos;
	t_color				color;
}						t_light;


typedef struct			s_scene
{
	int					nm;
	int					ns;
	int					nl;
	int					cs;
	t_material			*material;
	t_sphere			*sphere;
	t_light				*light;
	t_color				color;
}						t_scene;

typedef struct			s_img
{
	char				*d;
	int					bpp;
	int					endian;
	int					line_size;
	void				*img;
}						t_img;

typedef struct			s_env
{
	t_scene				*sc;
	void				*mlx;
	void				*win;
	t_img				*f;
	int					color;
}						t_env;

// DRAW
void					put_pixel(t_img *e, int x, int y, int color);
int						try_color(int red, int blue, int green);
int						trace_img(t_env *e, t_scene *sc);

// INIT
t_env					*init_env();
t_scene					*init_scene(char *av);

//VECTOR
t_vec					vec_sub(t_vec *v1, t_vec *v2);
t_vec					vec_add(t_vec *v1, t_vec *v2);
t_vec					vec_scal(float c, t_vec *v);
float					vec_dot(t_vec *v1, t_vec *v2);

//LIGHT
void					get_light_pos(int fd, char *line, t_scene *sc);
void					get_light_intensity(int fd, char *line, t_scene *sc);
void					get_light(int fd, t_scene *sc);

//MATERIAL
void					get_material(int fd, t_scene *sc);

//SPHERE
void					get_sphere_pos(int fd, char *line, t_scene *sc);
void					get_sphere_rayon(int fd, char *line, t_scene *sc);
void					get_sphere_material(int fd, char *line, t_scene *sc);
void					get_sphere(int fd, t_scene *sc);

//MAIN
int						main(int ac, char **av);
int						key_hook(int keycode, t_env *e);

//MISC
t_color					init_color(void);
t_ray					init_ray(int x, int y);
int						closest(t_scene *sc, t_ray r, float *t);
void					bla(float coef, t_scene *sc, t_vec *n, t_vec *newStart);

//PARSE
float					get_num(char **s);
t_vec					get_position(int fd);
void					clear_scene(t_scene *sc);
t_color					get_color(int fd);
void					get_number_of(char *line, t_scene *sc);

//RAY TRACING
int						intersection(t_ray *r, t_sphere *s, float *t);


#endif
