/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:56 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:57 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	get_hit_cy_co(t_object *obj)
{
	if ((obj->type == CYLINDER || obj->type == CONE)
		&& obj->hit.type == BODY)
	{
		obj->hit.normalize = vector_substract(
				vector_substract(obj->hit.point, obj->center),
				vect_mult(obj->normalize, obj->hit.m));
	}
	if (obj->type == CONE && obj->hit.type == BODY)
	{
		obj->hit.normalize = vector_substract(obj->hit.normalize,
				vect_mult(obj->normalize, tan(obj->radius / obj->height)
					* tan(obj->radius / obj->height) * obj->hit.m));
	}
}

t_vector	get_hit_direction(t_object *obj, t_vector ray)
{
	obj->hit.point = vect_mult(ray, obj->hit.dist);
	if (obj->type == SPHERE)
		obj->hit.normalize = vector_substract(obj->hit.point, obj->center);
	else if ((obj->type == CYLINDER || obj->type == CONE)
		&& obj->hit.type == BODY)
		get_hit_cy_co(obj);
	else if (obj->type == PLANE || obj->hit.type == CAP)
	{
		obj->hit.normalize = obj->normalize;
		if (dot_product(ray, obj->normalize) > 0.0)
			obj->hit.is_inside = 1;
	}
	if (obj->hit.is_inside)
		obj->hit.normalize = vect_mult(obj->hit.normalize, -1);
	normalization(&obj->hit.normalize);
	return (obj->hit.normalize);
}

inline static void	update_point_vals(	t_minirt *minirt, t_point *point,
										t_object *obj, t_vector ray)
{
	if (obj == NULL)
	{
		point->color = COL_BLACK;
		return ;
	}
	point->rgb = obj->rgb;
	if (obj->type == SPHERE)
	{
		if (minirt->apply_checkerboard)
			point->rgb = checkerboard(obj, point);
		if (minirt->apply_texture || minirt->apply_bump)
			point->rgb = patterns(obj, ray, minirt);
	}
	point->color = rgb_hex(0, point->rgb);
	if (obj->type == LIGHT)
		return ;
	point->normalize = get_hit_direction(obj, ray);
	point->hit_coord = obj->hit.point;
	point->type = obj->type;
	update_point_color(&minirt->scene, point, ray);
}

t_object	*object_intersects(t_minirt *minirt,
							t_object **objs, t_vector ray, t_point *point)
{
	int			i;
	float		res;

	i = 0;
	point->obj = NULL;
	point->dist = INFINITY;
	while (objs[i] != NULL)
	{
		if (objs[i]->type == SPHERE || objs[i]->type == LIGHT)
			res = sphere_intersect(minirt->scene.camera.point, objs[i], ray);
		else if (objs[i]->type == CYLINDER)
			res = cylinder_intersect(minirt->scene.camera.point, objs[i], ray);
		else if (objs[i]->type == PLANE)
			res = plane_intersect(minirt->scene.camera.point, objs[i], ray);
		else if (objs[i]->type == CONE)
			res = cone_intersect(minirt->scene.camera.point, objs[i], ray);
		if (res != 0 && res < point->dist)
		{
			point->obj = objs[i];
			point->dist = res;
		}
		i++;
	}
	update_point_vals(minirt, point, point->obj, ray);
	return (point->obj);
}
