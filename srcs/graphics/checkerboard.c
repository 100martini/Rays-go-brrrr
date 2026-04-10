/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:10 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:13 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	checkerboard(t_object *sphere, t_point *point)
{
	double		v;
	double		u;
	double		theta;
	double		phi;
	t_vector	upd_point;

	upd_point = vector_substract(point->hit_coord, sphere->center);
	theta = atan2(upd_point.x, upd_point.z);
	phi = acos(upd_point.y / sphere->radius);
	u = theta / (2 * M_PI);
	u = floor(10 * (1 - (u + 0.5)));
	v = floor(10 * (1 - (phi / M_PI)) / 2);
	if (fmod(u + v, 2) == 0)
		return (invert_colors(sphere->rgb));
	else
		return (sphere->rgb);
}
