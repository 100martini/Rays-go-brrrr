/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:32 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:34 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	sin_a_cos_camera(float *cos_a, float *sin_a, float angle_a,
								char direction)
{
	*cos_a = cosf(angle_a * direction);
	*sin_a = sinf(angle_a * direction);
}

void	camera_rotation(t_scene *scene)
{
	camera_x_rotation(scene);
	camera_y_rotation(scene);
	camera_z_rotation(scene);
}
