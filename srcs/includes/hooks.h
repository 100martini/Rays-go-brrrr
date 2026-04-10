/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:50 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:51 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "./minirt.h"
# include "./error.h"
# include "../../libs/mlx/mlx.h"

//REGISTER_HOOKS
void	hooks(t_minirt *minirt);

//EXIT
int		exit_hook(int keycode, t_minirt *minirt);
int		redcross_hook(t_minirt *minirt);

//MOVE_UTILITIES
void	move_x_axis(t_minirt *minirt, char sign);
void	move_y_axis(t_minirt *minirt, char sign);
void	move_z_axis(t_minirt *minirt, char sign);

//MOVE_QE
void	move_q(t_minirt *minirt);
void	move_e(t_minirt *minirt);

//MOVE_WASD
void	move_w(t_minirt *minirt);
void	move_a(t_minirt *minirt);
void	move_s(t_minirt *minirt);
void	move_d(t_minirt *minirt);

//ROTATION_UTILITIES
void	sin_a_cos(float *cos_a, float *sin_a, char direction);
void	axis_x_rotation(t_object **objs, float cos_a, float sin_a);
void	axis_x_rotation_lights(t_light **lights, float cos_a, float sin_a);
void	axis_y_rotation(t_object **objs, float cos_a, float sin_a);
void	axis_y_rotation_lights(t_light **lights, float cos_a, float sin_a);

//ROTATION
void	rotation_x(t_minirt *minirt, char direction);
void	rotation_y(t_minirt *minirt, char direction);
void	camera_x_rotation(t_scene *scene);
void	camera_y_rotation(t_scene *scene);
void	camera_z_rotation(t_scene *scene);

//CHANGE_SETTINGS
void	change_radius(t_minirt *minirt, char sign);
void	change_height(t_minirt *minirt, char sign);
void	change_brightness(t_minirt *minirt, char sign);

//PATTERN_SETTINGS
void	apply_texture(t_minirt *minirt);
void	apply_bump(t_minirt *minirt);
void	apply_checkerboard(t_minirt *minirt);

//OBJECT_SELECTION
void	selection(int mx, int my, t_minirt *minirt);
#endif
