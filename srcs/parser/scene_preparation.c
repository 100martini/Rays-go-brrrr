/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_preparation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:38 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:39 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	shift_point(t_vector *point, t_vector *shift)
{
	point->x += -shift->x;
	point->y += -shift->y;
	point->z += -shift->z;
}

void	shift_camera(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->count.lights && scene->lights[i])
	{
		shift_point(&scene->lights[i]->point, &scene->camera.point);
		shift_point(&scene->lights[i]->point, &scene->camera.orientation);
		i++;
	}
	i = 0;
	while (scene->objs[i])
	{
		shift_point(&scene->objs[i]->center, &scene->camera.point);
		i++;
	}
	scene->camera.point.x = 0;
	scene->camera.point.y = 0;
	scene->camera.point.z = 0;
}

void	prepare_scene(t_scene *scene)
{
	if (!scene->count.ambients)
		ft_error(AMBIENT_NDECL, scene);
	if (!scene->count.cameras)
		ft_error(CAMERA_NDECL, scene);
	if (!scene->count.lights)
		ft_error(LIGHT_NDECL, scene);
	scene->lights = convert_lights2arr(scene);
	if (!scene->count.objects)
		ft_error(OBJECT_NDECL, scene);
	scene->objs = convert_objects2arr(scene);
	scene->origin_color = get_rgb(0, 0, 0);
	scene->light = 0;
	scene->object = 0;
	shift_camera(scene);
	camera_rotation(scene);
}
