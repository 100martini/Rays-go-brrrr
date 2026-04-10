/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:21 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:22 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	move_x_axis(t_minirt *minirt, char sign)
{
	int	i;

	i = 0;
	while (minirt->scene.objs[i])
	{
		minirt->scene.objs[i]->center.x += 1 * sign;
		i++;
	}
	i = 0;
	while (minirt->scene.lights[i])
	{
		minirt->scene.lights[i]->point.x += 1 * sign;
		i++;
	}
}

void	move_y_axis(t_minirt *minirt, char sign)
{
	int	i;

	i = 0;
	while (minirt->scene.objs[i])
	{
		minirt->scene.objs[i]->center.y += 1 * sign;
		i++;
	}
	i = 0;
	while (minirt->scene.lights[i])
	{
		minirt->scene.lights[i]->point.y += 1 * sign;
		i++;
	}
}

void	move_z_axis(t_minirt *minirt, char sign)
{
	int	i;

	i = 0;
	while (minirt->scene.objs[i])
	{
		minirt->scene.objs[i]->center.z += 1 * sign;
		i++;
	}
	i = 0;
	while (minirt->scene.lights[i])
	{
		minirt->scene.lights[i]->point.z += 1 * sign;
		i++;
	}
}
