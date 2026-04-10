/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:13 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:14 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

static int	select_object(int button, int x, int y, t_minirt *minirt)
{
	(void)minirt;
	if (button == 1 && (x >= 0 && x <= WIN_WIDTH) && (y >= 0
			&& y <= WIN_HEIGHT))
		selection(x, y, minirt);
	return (0);
}

static void	ft_orientation_hook(int keycode, t_minirt *minirt)
{
	if (keycode == KEY_Q)
		move_q(minirt);
	else if (keycode == KEY_W)
		move_w(minirt);
	else if (keycode == KEY_E)
		move_e(minirt);
	else if (keycode == KEY_A)
		move_a(minirt);
	else if (keycode == KEY_S)
		move_s(minirt);
	else if (keycode == KEY_D)
		move_d(minirt);
	else if (keycode == KEY_LEFT)
		rotation_x(minirt, -1);
	else if (keycode == KEY_RIGHT)
		rotation_x(minirt, 1);
	else if (keycode == KEY_DOWN)
		rotation_y(minirt, -1);
	else if (keycode == KEY_UP)
		rotation_y(minirt, 1);
}

static void	ft_manipulation_hook(int keycode, t_minirt *minirt)
{
	if (keycode == KEY_1)
		change_radius(minirt, -1);
	else if (keycode == KEY_2)
		change_radius(minirt, 1);
	else if (keycode == KEY_3)
		change_height(minirt, -1);
	else if (keycode == KEY_4)
		change_height(minirt, 1);
	else if (keycode == KEY_MINUS)
		change_brightness(minirt, -1);
	else if (keycode == KEY_PLUS)
		change_brightness(minirt, 1);
	else if (keycode == KEY_T)
		apply_texture(minirt);
	else if (keycode == KEY_B)
		apply_bump(minirt);
	else if (keycode == KEY_C)
		apply_checkerboard(minirt);
}

static int	ft_hook(int keycode, t_minirt *minirt)
{
	ft_orientation_hook(keycode, minirt);
	ft_manipulation_hook(keycode, minirt);
	if (keycode == KEY_ESC)
		exit_hook(keycode, minirt);
	return (0);
}

void	hooks(t_minirt *minirt)
{
	mlx_mouse_hook(minirt->win, select_object, minirt);
	mlx_hook(minirt->win, 17, 1L << 17, redcross_hook, minirt);
	mlx_hook(minirt->win, 2, 1, ft_hook, minirt);
}
