/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:02 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:03 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static inline float	find_dists(t_object *obj, t_vector ray, t_eq eq)
{
	(void )ray;
	eq.discr = eq.b * eq.b - (4 * eq.a * eq.c);
	if (eq.discr < 0.0)
		return (0);
	eq.discr = sqrt(eq.discr);
	eq.dist1 = (-eq.b - eq.discr) / (2 * eq.a);
	eq.dist2 = (-eq.b + eq.discr) / (2 * eq.a);
	obj->hit.is_inside = 1;
	if (eq.dist1 > MIN_DIST || eq.dist2 > MIN_DIST)
	{
		if (eq.dist1 > MIN_DIST && eq.dist2 > MIN_DIST)
		{
			obj->hit.dist = fmin(eq.dist1, eq.dist2);
			obj->hit.is_inside = 0;
		}
		else if (eq.dist1 > MIN_DIST)
			obj->hit.dist = eq.dist1;
		else
			obj->hit.dist = eq.dist2;
		return (obj->hit.dist);
	}
	return (0);
}

float	sphere_intersect(t_vector origin, t_object *obj, t_vector ray)
{
	t_vector	orig_sp;
	t_eq		eq;

	orig_sp = vector_substract(origin, obj->center);
	eq.a = 1;
	eq.b = 2 * (dot_product(orig_sp, ray));
	eq.c = dot_product(orig_sp, orig_sp) - obj->radius * obj->radius;
	return (find_dists(obj, ray, eq));
}
