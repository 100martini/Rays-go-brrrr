/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:47 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:49 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_rgb	add_diff_light(t_light *light, t_point *point)
{
	float		intens;
	t_vector	l_len;

	l_len = vector_substract(light->point, point->hit_coord);
	intens = light->brightness * fmax(point->dist, 0)
		* (10 / vector_len(l_len));
	return (calcul_rgb_light(light->rgb, intens));
}

static t_rgb	add_specular(t_vector ray, t_point *point, t_light *light)
{
	t_vector	half_vect;
	t_vector	to_cam;
	double		strength;
	float		r_dot_v;

	to_cam = vect_mult(ray, -1);
	normalization(&to_cam);
	half_vect = vect_add(point->light_direction, to_cam);
	normalization(&half_vect);
	r_dot_v = dot_product(half_vect, point->normalize);
	strength = light->brightness * pow(fmax(r_dot_v, 0.0), 100);
	return (calcul_rgb_light(light->rgb, 0.6 * strength));
}

static int	intersection_count(	t_object **objs,
									t_point *intx, t_object *current)
{
	float		res;
	int			i;

	i = 0;
	res = 0;
	intx->dist = INFINITY;
	while (objs[i] != NULL)
	{
		if (current != objs[i] && objs[i]->type == SPHERE)
			res = sphere_intersect(intx->hit_coord, objs[i], intx->normalize);
		else if (current != objs[i] && objs[i]->type == CYLINDER)
			res = cylinder_intersect(intx->hit_coord, objs[i], intx->normalize);
		else if (current != objs[i] && objs[i]->type == PLANE)
			res = plane_intersect(intx->hit_coord, objs[i], intx->normalize);
		else if (current != objs[i] && objs[i]->type == CONE)
			res = cone_intersect(intx->hit_coord, objs[i], intx->normalize);
		if (res != 0.0 && res < intx->dist)
			intx->dist = res;
		i++;
	}
	if (intx->dist == INFINITY)
		return (0);
	intx->hit_coord = vect_add(vect_mult(intx->normalize, intx->dist),
			intx->hit_coord);
	return (1);
}

static int	in_shadow(t_scene *scene, t_point *point, t_light *light)
{
	t_point		intersect;
	float		dist_to_light;
	float		dist_to_obj;

	intersect.hit_coord = vect_add(point->hit_coord,
			vect_mult(point->normalize, 0.00001));
	intersect.normalize = vector_substract(light->point, intersect.hit_coord);
	normalization(&intersect.normalize);
	if (intersection_count(scene->objs, &intersect, point->obj))
	{
		dist_to_light = point_dist(point->hit_coord, light->point);
		dist_to_obj = point_dist(point->hit_coord, intersect.hit_coord);
		if (dist_to_obj < dist_to_light)
			return (1);
	}
	return (0);
}

void	update_point_color(t_scene *scene, t_point *point, t_vector ray)
{
	t_rgb		color;
	int			i;

	i = 0;
	color = calcul_rgb_light(scene->ambient.rgb, scene->ambient.brightness);
	while (scene->lights[i])
	{
		point->light_direction = vector_substract(scene->lights[i]->point,
				point->hit_coord);
		normalization(&point->light_direction);
		point->dist = dot_product(point->normalize, point->light_direction);
		if (!in_shadow(scene, point, scene->lights[i]))
		{
			if (point->dist > 0.0)
				color = add_rgb_light(
						add_diff_light(scene->lights[i], point), color);
			color = add_rgb_light(
					add_specular(ray, point, scene->lights[i]), color);
		}
		i++;
	}
	point->rgb = multiply_rgbs(point->rgb, color);
	point->color = rgb_hex(0, point->rgb);
}
