/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:34 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:35 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	sin_a_cos(float *cos_a, float *sin_a, char direction)
{
	float	angle_a;

	if (direction > 0)
		angle_a = -0.1;
	else if (direction < 0)
		angle_a = 0.1;
	else
		angle_a = 0;
	*cos_a = cosf(angle_a);
	*sin_a = sinf(angle_a);
}

void	axis_x_rotation(t_object **objs, float cos_a, float sin_a)
{
	int		i;
	float	rx;
	float	rz;

	i = 0;
	while (objs[i])
	{
		rx = objs[i]->center.x * cos_a - objs[i]->center.z * sin_a;
		rz = objs[i]->center.x * sin_a + objs[i]->center.z * cos_a;
		objs[i]->center.x = rx;
		objs[i]->center.z = rz;
		if (objs[i]->normalize.x || objs[i]->normalize.y
			|| objs[i]->normalize.z)
		{
			rx = objs[i]->normalize.x * cos_a - objs[i]->normalize.z * sin_a;
			rz = objs[i]->normalize.x * sin_a + objs[i]->normalize.z * cos_a;
			objs[i]->normalize.x = rx;
			objs[i]->normalize.z = rz;
		}
		i++;
	}
}

void	axis_x_rotation_lights(t_light **lights, float cos_a, float sin_a)
{
	int		i;
	float	rx;
	float	rz;

	i = 0;
	while (lights[i])
	{
		rx = lights[i]->point.x * cos_a - lights[i]->point.z * sin_a;
		rz = lights[i]->point.x * sin_a + lights[i]->point.z * cos_a;
		lights[i]->point.x = rx;
		lights[i]->point.z = rz;
		i++;
	}
}

void	axis_y_rotation(t_object **objs, float cos_a, float sin_a)
{
	int		i;
	float	ry;
	float	rz;

	i = 0;
	while (objs[i])
	{
		ry = objs[i]->center.y * cos_a - objs[i]->center.z * sin_a;
		rz = objs[i]->center.y * sin_a + objs[i]->center.z * cos_a;
		objs[i]->center.y = ry;
		objs[i]->center.z = rz;
		if (objs[i]->normalize.x || objs[i]->normalize.y
			|| objs[i]->normalize.z)
		{
			ry = objs[i]->normalize.y * cos_a - objs[i]->normalize.z * sin_a;
			rz = objs[i]->normalize.y * sin_a + objs[i]->normalize.z * cos_a;
			objs[i]->normalize.y = ry;
			objs[i]->normalize.z = rz;
		}
		i++;
	}
}

void	axis_y_rotation_lights(t_light **lights, float cos_a, float sin_a)
{
	int		i;
	float	ry;
	float	rz;

	i = 0;
	while (lights[i])
	{
		ry = lights[i]->point.y * cos_a - lights[i]->point.z * sin_a;
		rz = lights[i]->point.y * sin_a + lights[i]->point.z * cos_a;
		lights[i]->point.y = ry;
		lights[i]->point.z = rz;
		i++;
	}
}
