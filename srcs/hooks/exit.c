/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:10 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/23 10:48:22 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	destroy_graphics(t_minirt *minirt)
{
	if (minirt->texture.img)
		mlx_destroy_image(minirt->mlx, minirt->texture.img);
	if (minirt->bump.img)
		mlx_destroy_image(minirt->mlx, minirt->bump.img);
	if (minirt->img)
		mlx_destroy_image(minirt->mlx, minirt->img);
	if (minirt->win)
		mlx_destroy_window(minirt->mlx, minirt->win);
	if (minirt->mlx)
	{
		mlx_destroy_display(minirt->mlx);
		free(minirt->mlx);
	}
}

int	exit_hook(int keycode, t_minirt *minirt)
{
	if (65307 == keycode || 113 == keycode)
	{
		free_scene(&minirt->scene);
		destroy_graphics(minirt);
		printf("You pressed [ESC] button.\n" TC_OK \
			"Exiting program!\n\n" COLOR_END);
		exit(0);
	}
	return (0);
}

int	redcross_hook(t_minirt *minirt)
{
	free_scene(&minirt->scene);
	destroy_graphics(minirt);
	printf("You clicked on the red cross on the window’s \
		frame.\n" TC_OK "Exiting program!\n\n" COLOR_END);
	exit(0);
}
