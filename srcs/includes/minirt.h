/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:54 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:55 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// Arrow keys
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

// Number keys
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52

// Misc keys
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_T 116
# define KEY_B 98
# define KEY_C 99
# define KEY_ESC 65307

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

# define MIN_DIST 0.0001
# define MAX_DIST 100000000.0

# define COL_RED 0x00D13632
# define COL_ORANGE 0x00E2571E
# define COL_YELLOW 0x00CDB924
# define COL_GREEN 0x00479E1B
# define COL_BLUE 0x001D829E
# define COL_VIOLET 0x00503FA9
# define COL_BLACK 0x002B2B2A

# include "errors.h"
# include "parsing.h"
# include "../../libs/mlx/mlx.h"
# include "prototypes.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

void		ft_print_scene(t_scene *scene);

t_rgb		patterns(t_object *obj, t_vector ray, t_minirt *minirt);
t_rgb		checkerboard(t_object *sphere, t_point *point);

/* drawing functions */
void		ft_put_pixel(t_minirt *gl, int x, int y, int color);
void		pixel_put(t_minirt *minirt, int x, int y, int color);
void		fill_background(t_minirt *minirt);

/* colors */
int			rgb_hex(int t, t_rgb rgb);
t_rgb		get_rgb(int r, int g, int b);
t_rgb		rgb2gray(t_rgb rgb);
t_rgb		invert_colors(t_rgb color);
t_rgb		rgb_brightness_adjust(t_rgb rgb, float adjust);

/* hooks */
void		hooks(t_minirt *minirt);

/* memory handling */
void		*ft_memset(void *b, int c, size_t len);

/* graphics */
void		graphics(t_scene *scene);
t_plane		get_projection_plane(float scene_w, float scene_h, float angle);
void		ray_tracing(t_minirt *minirt);
t_object	*object_intersects(t_minirt *minirt, t_object **objs, t_vector ray,
				t_point *point);
float		sphere_intersect(t_vector origin, t_object *obj, t_vector ray);
float		plane_intersect(t_vector origin, t_object *obj, t_vector ray);
float		cylinder_intersect(t_vector origin, t_object *obj, t_vector ray);
float		cone_intersect(t_vector origin, t_object *obj, t_vector ray);
t_vector	get_hit_direction(t_object *obj, t_vector ray);
int			get_cylinder_caps(t_eq *caps, t_object *obj, t_vector ray,
				t_vector origin);
int			get_cone_caps(t_eq *cap, t_object *obj, t_vector ray,
				t_vector origin);

/* light functions */
void		update_point_color(t_scene *scene, t_point *point, t_vector ray);

t_rgb		calcul_rgb_light(t_rgb color, double light);
t_rgb		multiply_rgbs(t_rgb a, t_rgb b);
t_rgb		add_rgb_light(t_rgb a, t_rgb b);
t_rgb		invert_colors(t_rgb color);

/* vector functions */
t_vector	new_vector(float x, float y, float z);
t_vector	vect_add(t_vector v1, t_vector v2);
t_vector	vector_substract(t_vector v1, t_vector v2);
float		vector_len(t_vector vect);
void		normalization(t_vector *vect);
float		dot_product(t_vector v1, t_vector v2);
t_vector	vect_mult(t_vector vect, float n);
t_vector	vect_div(t_vector vect, float n);
float		point_dist(t_vector v1, t_vector v2);
t_vector	vector_rotate_cw(t_vector vector);
t_vector	vector_rotate_ccw(t_vector vector);

#endif
