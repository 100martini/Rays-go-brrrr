/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_qe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:18 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:19 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	move_q(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_y_axis(minirt, 1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.y += 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.y += 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	move_e(t_minirt *minirt)
{
	if (!minirt->scene.object)
		move_y_axis(minirt, -1);
	else if (minirt->scene.object)
	{
		minirt->scene.object->center.y -= 1;
		if (minirt->scene.object->type == 'L')
			minirt->scene.light->point.y -= 1;
	}
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
