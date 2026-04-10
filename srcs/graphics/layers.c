/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:36 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/22 22:55:55 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_pattern	get_pattern(t_minirt *minirt, char *filename)
{
	t_pattern	tmp;

	tmp.img = 0;
	tmp.addr = 0;
	if (filename)
		tmp.img = mlx_xpm_file_to_image(minirt->mlx, filename,
				&tmp.width, &tmp.height);
	if (tmp.img)
		tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel,
				&tmp.size_line, &tmp.endian);
	if (!tmp.img || !tmp.addr)
		printf(COLOR_ERROR"Failed to load %s pattern"COLOR_END"\n", filename);
	return (tmp);
}

void	init_graphics(t_minirt *minirt, t_scene *scene)
{
	minirt->size_x = WIN_WIDTH;
	minirt->size_y = WIN_HEIGHT;
	minirt->mlx = mlx_init();
	minirt->win = mlx_new_window(minirt->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	minirt->img = mlx_new_image(minirt->mlx, WIN_WIDTH, WIN_HEIGHT);
	minirt->addr = mlx_get_data_addr(minirt->img, &minirt->bits_per_pixel,
			&minirt->line_length, &minirt->endian);
	minirt->bits_per_pixel /= 8;
	minirt->scene = *scene;
	minirt->texture = get_pattern(minirt, "./patterns/texture.xpm");
	minirt->bump = get_pattern(minirt, "./patterns/bump.xpm");
	minirt->apply_texture = 0;
	minirt->apply_bump = 0;
	minirt->apply_checkerboard = 0;
}

void	graphics(t_scene *scene)
{
	t_minirt	minirt;

	init_graphics(&minirt, scene);
	ray_tracing(&minirt);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	hooks(&minirt);
	mlx_loop(minirt.mlx);
}
