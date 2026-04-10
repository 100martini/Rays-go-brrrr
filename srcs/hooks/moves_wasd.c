/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_wasd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:24 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:25 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	move_w(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_z_axis(minirt, 1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.z -= 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.z -= 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	move_a(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_x_axis(minirt, 1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.x -= 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.x -= 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	move_s(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_z_axis(minirt, -1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.z += 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.z += 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	move_d(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_x_axis(minirt, -1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.x += 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.x += 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
