/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:43 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:45 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	ft_list_elements(void *p, char type)
{
	int			i;
	t_light		*light;
	t_object	*object;

	i = 0;
	if (type == 'L')
	{
		light = (t_light *)p;
		while (light)
		{
			i++;
			light = light->next;
		}
	}
	else if (type == 'O')
	{
		object = (t_object *)p;
		while (object)
		{
			i++;
			object = object->next;
		}
	}
	return (i);
}

t_light	**convert_lights2arr(t_scene *scene)
{
	int			i;
	t_light		**lights;
	t_light		*p;

	while (scene->light->previous)
		scene->light = scene->light->previous;
	i = ft_list_elements(scene->light, 'L');
	lights = lights_init(i, scene);
	i = 0;
	p = scene->light;
	while (p)
	{
		lights[i] = p;
		if (lights[i]->previous)
			lights[i]->previous->next = 0;
		lights[i]->previous = 0;
		i++;
		p = p->next;
	}
	return (lights);
}

t_object	**convert_objects2arr(t_scene *scene)
{
	int			i;
	t_object	*p;
	t_object	**objects;

	while (scene->object->previous)
		scene->object = scene->object->previous;
	i = ft_list_elements(scene->object, 'O');
	objects = ft_objects_init(i, scene);
	i = 0;
	p = scene->object;
	while (p)
	{
		objects[i] = p;
		if (objects[i]->previous)
			objects[i]->previous->next = 0;
		objects[i]->previous = 0;
		i++;
		p = p->next;
	}
	return (objects);
}

void	light_as_objects(t_scene *scene, t_light *light)
{
	if (!scene->object)
		scene->object = init_object(scene);
	else
	{
		scene->object->next = init_object(scene);
		scene->object->next->previous = scene->object;
		scene->object = scene->object->next;
	}
	scene->object->type = LIGHT;
	scene->object->center = light->point;
	scene->object->radius = 0.5;
	scene->object->rgb = light->rgb;
	scene->object->light = light;
}
