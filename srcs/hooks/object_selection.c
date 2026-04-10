/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:28 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:29 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../../libs/mlx/mlx.h"

static void	first_obj_selection(t_minirt *minirt, t_object *tmp_obj)
{
	minirt->scene.object = tmp_obj;
	minirt->scene.origin_color = tmp_obj->rgb;
	if (minirt->scene.object->type == 'L')
	{
		minirt->scene.light = minirt->scene.object->light;
		minirt->scene.object->rgb = get_rgb(65, 255, 125);
	}
	else
		minirt->scene.object->rgb = get_rgb(255, 125, 0);
}

static void	deselect(t_minirt *minirt)
{
	minirt->scene.object->rgb = minirt->scene.origin_color;
	minirt->scene.object = 0;
	minirt->scene.light = 0;
	minirt->scene.origin_color = get_rgb(0, 0, 0);
}

static void	change_selected_obj(t_minirt *minirt, t_object *tmp_obj)
{
	minirt->scene.object->rgb = minirt->scene.origin_color;
	minirt->scene.object = tmp_obj;
	minirt->scene.origin_color = tmp_obj->rgb;
	if (minirt->scene.object->type == 'L')
	{
		minirt->scene.light = minirt->scene.object->light;
		minirt->scene.object->rgb = get_rgb(65, 255, 125);
	}
	else
		minirt->scene.object->rgb = get_rgb(255, 125, 0);
}

static void	cancel_selection(t_minirt *minirt)
{
	minirt->scene.object = 0;
	minirt->scene.light = 0;
	minirt->scene.origin_color = get_rgb(0, 0, 0);
}

void	selection(int mx, int my, t_minirt *minirt)
{
	t_plane		proj;
	t_vector	ray;
	t_point		point;
	t_object	*tmp_obj;

	mx = mx - (WIN_WIDTH / 2);
	my = (WIN_HEIGHT / 2.0) - my;
	proj = get_projection_plane(WIN_WIDTH, WIN_HEIGHT,
			minirt->scene.camera.fov);
	ray = new_vector(mx * proj.x_pix, my * proj.y_pix, -1.0);
	normalization(&ray);
	tmp_obj = object_intersects(minirt, minirt->scene.objs, ray, &point);
	if (!minirt->scene.object && tmp_obj)
		first_obj_selection(minirt, tmp_obj);
	else if ((minirt->scene.object && !tmp_obj) || (tmp_obj
			&& minirt->scene.object == tmp_obj))
		deselect(minirt);
	else if (minirt->scene.object && tmp_obj && minirt->scene.object != tmp_obj)
		change_selected_obj(minirt, tmp_obj);
	else
		cancel_selection(minirt);
	ray_tracing(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
}
