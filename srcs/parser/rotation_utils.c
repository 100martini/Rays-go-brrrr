/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:27 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:28 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	sin_a_cos_camera(float *cos_a, float *sin_a, float angle_a,
			char direction);

void	camera_x_rotation(t_scene *scene)
{
	float	cos_a;
	float	sin_a;

	cos_a = 0;
	if (scene->camera.orientation.x == 1)
		sin_a = -1;
	else if (scene->camera.orientation.x == -1)
		sin_a = 1;
	else
		sin_a_cos_camera(&cos_a, &sin_a,
			scene->camera.orientation.x, -1);
	axis_x_rotation(scene->objs, cos_a, sin_a);
	axis_x_rotation_lights(scene->lights, cos_a, sin_a);
	scene->camera.orientation.x = 0;
}

void	camera_y_rotation(t_scene *scene)
{
	float	cos_a;
	float	sin_a;

	cos_a = 0;
	if (scene->camera.orientation.y == 1)
		sin_a = -1;
	else if (scene->camera.orientation.y == -1)
		sin_a = 1;
	else
		sin_a_cos_camera(&cos_a, &sin_a,
			scene->camera.orientation.y, -1);
	axis_y_rotation(scene->objs, cos_a, sin_a);
	axis_y_rotation_lights(scene->lights, cos_a, sin_a);
	scene->camera.orientation.y = 0;
}

static void	axis_x_roation_objs(t_object **objs, float cos_a, float sin_a)
{
	int		i;
	float	rx;
	float	ry;

	i = 0;
	while (objs[i])
	{
		rx = objs[i]->center.x * cos_a - objs[i]->center.y * sin_a;
		ry = objs[i]->center.x * sin_a + objs[i]->center.y * cos_a;
		objs[i]->center.x = rx;
		objs[i]->center.y = ry;
		if (objs[i]->normalize.x || objs[i]->normalize.y || \
			objs[i]->normalize.z)
		{
			rx = objs[i]->normalize.x * cos_a - objs[i]->normalize.y * sin_a;
			ry = objs[i]->normalize.x * sin_a + objs[i]->normalize.y * cos_a;
			objs[i]->normalize.x = rx;
			objs[i]->normalize.y = ry;
		}
		i++;
	}
}

static void	axis_z_roation_lights(t_light **lights, float cos_a, float
sin_a)
{
	int		i;
	float	rx;
	float	ry;

	i = 0;
	while (lights[i])
	{
		rx = lights[i]->point.x * cos_a - lights[i]->point.y * sin_a;
		ry = lights[i]->point.x * sin_a + lights[i]->point.y * cos_a;
		lights[i]->point.x = rx;
		lights[i]->point.y = ry;
		i++;
	}
}

void	camera_z_rotation(t_scene *scene)
{
	float	cos_a;
	float	sin_a;

	if (scene->camera.orientation.z)
	{
		if (scene->camera.orientation.z > 0)
		{
			sin_a = 0;
			cos_a = -1;
			axis_y_rotation(scene->objs, cos_a, sin_a);
			axis_y_rotation_lights(scene->lights, cos_a, sin_a);
			sin_a_cos_camera(&cos_a, &sin_a,
				scene->camera.orientation.z, 1);
		}
		sin_a = 0;
		cos_a = -scene->camera.orientation.z;
		axis_x_roation_objs(scene->objs, cos_a, sin_a);
		axis_z_roation_lights(scene->lights, cos_a, sin_a);
	}
	scene->camera.orientation.z = 0;
}
