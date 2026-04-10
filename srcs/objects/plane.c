/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:59 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:00 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	plane_intersect(t_vector origin, t_object *obj, t_vector ray)
{
	float		dot_r_nv;
	t_vector	orig_pl;

	obj->hit.is_inside = 0;
	normalization(&obj->normalize);
	dot_r_nv = dot_product(ray, obj->normalize);
	if (dot_r_nv == 0 || fabs(dot_r_nv) < MIN_DIST)
		return (0);
	orig_pl = vector_substract(origin, obj->center);
	obj->hit.dist = -dot_product(orig_pl, obj->normalize) / dot_r_nv;
	if (obj->hit.dist < MIN_DIST || obj->hit.dist > MAX_DIST)
		return (0);
	return (obj->hit.dist);
}
