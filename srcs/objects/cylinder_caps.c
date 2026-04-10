/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:49 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:50 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	solve_caps(t_eq *caps, t_object *obj, t_vector ray)
{
	short		res[2];
	t_vector	cap_c[2];
	t_vector	hit[2];

	ft_memset(&res, 0, sizeof(res));
	if (caps->dist1 >= MIN_DIST)
	{
		hit[0] = vect_mult(ray, caps->dist1);
		cap_c[0] = vect_add(obj->center, vect_mult(obj->normalize, caps->m1));
		res[0] = (fabs(point_dist(hit[0], cap_c[0])) <= obj->radius);
	}
	if (caps->dist2 >= MIN_DIST)
	{
		hit[1] = vect_mult(ray, caps->dist2);
		cap_c[1] = vect_add(obj->center, vect_mult(obj->normalize, caps->m2));
		res[1] = (fabs(point_dist(hit[1], cap_c[1])) <= obj->radius);
	}
	if (!res[0] && !res[1])
		return (0);
	if ((res[0] && res[1] && caps->dist2 < caps->dist1) || !res[0])
	{
		caps->dist1 = caps->dist2;
		caps->m1 = caps->m2;
	}
	return (1);
}

int	get_cylinder_caps(t_eq *caps, t_object *obj, t_vector ray, t_vector origin)
{
	float		dot_r_nv;
	t_vector	orig_pl1;
	t_vector	orig_pl2;

	normalization(&obj->normalize);
	dot_r_nv = dot_product(ray, obj->normalize);
	if (dot_r_nv == 0 || fabs(dot_r_nv) < MIN_DIST)
		return (0);
	caps->m1 = obj->height;
	caps->m2 = -obj->height;
	orig_pl1 = vector_substract(origin,
			vect_add(obj->center, vect_mult(obj->normalize, caps->m1)));
	orig_pl2 = vector_substract(origin,
			vect_add(obj->center, vect_mult(obj->normalize, caps->m2)));
	caps->dist1 = -dot_product(orig_pl1, obj->normalize) / dot_r_nv;
	caps->dist2 = -dot_product(orig_pl2, obj->normalize) / dot_r_nv;
	if (caps->dist1 < MIN_DIST && caps->dist2 < MIN_DIST)
		return (0);
	return (solve_caps(caps, obj, ray));
}

int	get_cone_caps(t_eq *cap, t_object *obj, t_vector ray, t_vector origin)
{
	float		dot_r_nv;
	t_vector	orig_pl;

	normalization(&obj->normalize);
	dot_r_nv = dot_product(ray, obj->normalize);
	if (dot_r_nv == 0 || fabs(dot_r_nv) < MIN_DIST)
		return (0);
	cap->m1 = obj->height;
	orig_pl = vector_substract(origin,
			vect_add(obj->center, vect_mult(obj->normalize, cap->m1)));
	cap->dist1 = -dot_product(orig_pl, obj->normalize) / dot_r_nv;
	if (cap->dist1 < MIN_DIST)
		return (0);
	cap->dist2 = -1;
	return (solve_caps(cap, obj, ray));
}
