/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:13 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:15 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_light	*init_light(t_scene *scene)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		ft_error(MALLOC_LIGHT, scene);
	ft_memset(light, 0, sizeof(t_light));
	return (light);
}

t_object	*init_object(t_scene *scene)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		ft_error(MALLOC_OBJECT, scene);
	ft_memset(object, 0, sizeof(t_object));
	return (object);
}

t_light	**lights_init(int i, t_scene *scene)
{
	t_light		**lights;

	lights = malloc(sizeof(t_light) * i);
	if (!lights)
		ft_error(MALLOC_LGHT_ARR, scene);
	ft_memset(lights, 0, sizeof(t_light) * i);
	return (lights);
}

t_object	**ft_objects_init(int i, t_scene *scene)
{
	t_object	**objects;

	objects = malloc(sizeof(t_object) * i);
	if (!objects)
		ft_error(MALLOC_OBJS_ARR, scene);
	ft_memset(objects, 0, sizeof(t_object) * i);
	return (objects);
}
