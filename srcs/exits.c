/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:45:04 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:45:05 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

static void	free_lights(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->lights)
	{
		while (scene->lights[i])
		{
			free(scene->lights[i]);
			i++;
		}
		free(scene->lights);
	}
}

static void	free_objects(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->objs)
	{
		while (scene->objs[i])
		{
			free(scene->objs[i]);
			i++;
		}
		free(scene->objs);
	}
}

void	free_scene(t_scene *scene)
{
	free_lights(scene);
	free_objects(scene);
}

void	ft_error(char *typerr, t_scene *scene)
{
	printf(COLOR_ERROR"Ghalat: ");
	printf("%s\n"COLOR_END, typerr);
	if (scene)
		free_scene(scene);
	exit(1);
}

void	ft_error02(char *typerr, t_vector *normalize)
{
	printf(COLOR_ERROR"Ghalat:");
	printf("%s\n"COLOR_END, typerr);
	normalization(normalize);
}
