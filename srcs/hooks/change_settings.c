/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:06 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:07 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	change_radius(t_minirt *minirt, char sign)
{
	if (minirt->scene.object && minirt->scene.object->type != 'L'
		&& ((minirt->scene.object->radius > 0.1 && sign < 0) || sign > 0))
		minirt->scene.object->radius += 0.05 * sign;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	change_height(t_minirt *minirt, char sign)
{
	if (minirt->scene.object && ((minirt->scene.object->height > 0.1
				&& sign < 0) || sign > 0))
		minirt->scene.object->height += 0.1 * sign;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	change_brightness(t_minirt *minirt, char sign)
{
	if (minirt->scene.light && ((minirt->scene.light->brightness > 0
				&& sign < 0) || (minirt->scene.light->brightness < 1
				&& sign > 0)))
		minirt->scene.light->brightness += 0.1 * sign;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
