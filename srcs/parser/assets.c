/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:43:54 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/22 21:20:20 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	colors(t_rgb c)
{
	if (c.r < 0 || c.r > 255 || c.g < 0 || c.g > 255 || c.b < 0 || c.b > 255)
		return (1);
	else
		return (0);
}

char	orientation(t_vector v)
{
	if (v.x < -1 || v.x > 1 || v.y < -1 || v.y > 1 || v.z < -1 || v.z > 1)
		return (1);
	else
		return (0);
}

void	ambient(t_scene *scene, char *str, int i)
{
	if (scene->count.ambients)
		ft_error(AMBIENT_DECL, scene);
	scene->ambient.brightness = ft_atof(str, &i);
	is_valid(str, i, scene);
	if (scene->ambient.brightness < 0 || scene->ambient.brightness > 1)
		ft_error(AMBIENT_LIGHT, scene);
	scene->ambient.rgb = parsing_colors(str, i, scene);
	if (colors(scene->ambient.rgb))
		ft_error(AMBIENT_COLOR, scene);
	scene->count.ambients++;
}

void	camera(t_scene *scene, char *str, int i)
{
	if (scene->count.cameras)
		ft_error(CAMERA_DECL, scene);
	scene->camera.point = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->camera.orientation = parsing_vectors(str, &i, scene);
	if (orientation(scene->camera.orientation))
		ft_error(CAMERA_ORIENT, scene);
	if (vector_len(scene->camera.orientation) != 1)
		ft_error02(CAMERA_NNORM, &scene->camera.orientation);
	is_valid(str, i, scene);
	scene->camera.fov = ft_atof(str, &i);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		ft_error(CAMERA_FOV, scene);
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i])
		ft_error(BAD_FORMAT, scene);
	scene->count.cameras++;
}

void	light(t_scene *scene, char *str, int i)
{
	if (!scene->light)
		scene->light = init_light(scene);
	else
	{
		scene->light->next = init_light(scene);
		scene->light->next->previous = scene->light;
		scene->light = scene->light->next;
	}
	scene->light->point = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->light->brightness = ft_atof(str, &i);
	is_valid(str, i, scene);
	if (scene->light->brightness < 0 || scene->light->brightness > 1)
		ft_error(LIGHT_BRIGHT, scene);
	scene->light->rgb = parsing_colors(str, i, scene);
	if (colors(scene->light->rgb))
		ft_error(LIGHT_COLOR, scene);
	scene->count.lights++;
}
