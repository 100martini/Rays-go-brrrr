/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:31 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:32 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	apply_texture(t_minirt *minirt)
{
	if (minirt->apply_texture)
		minirt->apply_texture = 0;
	else
		minirt->apply_texture = 1;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	apply_bump(t_minirt *minirt)
{
	if (minirt->apply_bump)
		minirt->apply_bump = 0;
	else
		minirt->apply_bump = 1;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}

void	apply_checkerboard(t_minirt *minirt)
{
	if (minirt->apply_checkerboard)
		minirt->apply_checkerboard = 0;
	else
		minirt->apply_checkerboard = 1;
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
