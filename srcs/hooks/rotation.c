/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:38 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:39 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	rotation_x(t_minirt *minirt, char direction)
{
	float	cos_a;
	float	sin_a;

	sin_a_cos(&cos_a, &sin_a, direction);
	if (!minirt->scene.object)
	{
		axis_x_rotation(minirt->scene.objs, cos_a, sin_a);
		axis_x_rotation_lights(minirt->scene.lights, cos_a, sin_a);
	}
	else if (minirt->scene.object->normalize.x
		|| minirt->scene.object->normalize.z)
	{
		minirt->scene.object->normalize.x = minirt->scene.object->normalize.x
			* cos_a - minirt->scene.object->normalize.z * sin_a;
		minirt->scene.object->normalize.z = minirt->scene.object->normalize.x
			* sin_a + minirt->scene.object->normalize.z * cos_a;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	rotation_y(t_minirt *minirt, char direction)
{
	float	cos_a;
	float	sin_a;

	sin_a_cos(&cos_a, &sin_a, direction);
	if (!minirt->scene.object)
	{
		axis_y_rotation(minirt->scene.objs, cos_a, sin_a);
		axis_y_rotation_lights(minirt->scene.lights, cos_a, sin_a);
	}
	else if (minirt->scene.object->normalize.y
		|| minirt->scene.object->normalize.z)
	{
		minirt->scene.object->normalize.y = minirt->scene.object->normalize.y
			* cos_a - minirt->scene.object->normalize.z * sin_a;
		minirt->scene.object->normalize.z = minirt->scene.object->normalize.y
			* sin_a + minirt->scene.object->normalize.z * cos_a;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
