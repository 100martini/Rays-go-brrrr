/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:18 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:20 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	sphere(t_scene *scene, char *str, int i)
{
	scene->object->type = SPHERE;
	scene->object->center = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->object->normalize.x = 0;
	scene->object->normalize.y = 1;
	scene->object->normalize.z = 0;
	scene->object->radius = ft_atof(str, &i) / 2;
	is_valid(str, i, scene);
	scene->object->rgb = parsing_colors(str, i, scene);
	if (colors(scene->object->rgb))
		ft_error(SPHERE_COLOR, scene);
	scene->count.objects++;
}

void	plane(t_scene *scene, char *str, int i)
{
	scene->object->type = PLANE;
	scene->object->center = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->object->normalize = parsing_vectors(str, &i, scene);
	if (orientation(scene->object->normalize))
		ft_error(PLANE_ORIENT, scene);
	if (vector_len(scene->object->normalize) != 1)
		ft_error02(PLANE_NNORM, &scene->object->normalize);
	is_valid(str, i, scene);
	scene->object->rgb = parsing_colors(str, i, scene);
	if (colors(scene->object->rgb))
		ft_error(PLANE_COLOR, scene);
	scene->count.objects++;
}

void	cylinder(t_scene *scene, char *str, int i)
{
	scene->object->type = CYLINDER;
	scene->object->center = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->object->normalize = parsing_vectors(str, &i, scene);
	if (orientation(scene->object->normalize))
		ft_error(CLND_ORIENT, scene);
	if (vector_len(scene->object->normalize) != 1)
		ft_error02(CLND_NNORM, &scene->object->normalize);
	is_valid(str, i, scene);
	scene->object->radius = ft_atof(str, &i) / 2;
	is_valid(str, i, scene);
	scene->object->height = ft_atof(str, &i) / 2;
	is_valid(str, i, scene);
	scene->object->rgb = parsing_colors(str, i, scene);
	if (colors(scene->object->rgb))
		ft_error(CLND_COLOR, scene);
	scene->count.objects++;
}

void	cone(t_scene *scene, char *str, int i)
{
	scene->object->type = CONE;
	scene->object->center = parsing_vectors(str, &i, scene);
	is_valid(str, i, scene);
	scene->object->normalize = parsing_vectors(str, &i, scene);
	if (orientation(scene->object->normalize))
		ft_error(CONE_ORIENT, scene);
	if (vector_len(scene->object->normalize) != 1)
		ft_error02(CONE_NNORM, &scene->object->normalize);
	is_valid(str, i, scene);
	scene->object->radius = ft_atof(str, &i) / 2;
	is_valid(str, i, scene);
	scene->object->height = ft_atof(str, &i);
	is_valid(str, i, scene);
	scene->object->rgb = parsing_colors(str, i, scene);
	if (colors(scene->object->rgb))
		ft_error(CONE_COLOR, scene);
	scene->count.objects++;
}
