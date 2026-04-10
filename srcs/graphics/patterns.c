/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:53 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:55 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	*get_pattern_addr(t_pattern pattern, double u, double v)
{
	int	x;
	int	y;

	x = (int)fmod(fmod(u, pattern.width) + pattern.width, pattern.width);
	y = (int)fmod(fmod(v, pattern.height) + pattern.height, pattern.height);
	x *= pattern.bits_per_pixel / 8;
	y *= pattern.size_line;
	return (pattern.addr + y + x);
}

static t_rgb	rgb_pattern(t_pattern pattern, double u, double v,
							float brightness)
{
	t_rgb	tmp;
	void	*color;

	brightness += 1;
	if (brightness > 1)
		brightness = 1;
	if (brightness < 0)
		brightness = 0;
	color = get_pattern_addr(pattern, u, v);
	tmp = get_rgb((*(unsigned int *) color & 0x00ff0000) >> 16,
			(*(unsigned int *) color & 0x0000ff00) >> 8,
			(*(unsigned int *) color & 0x000000ff));
	tmp = rgb_brightness_adjust(tmp, brightness);
	return (tmp);
}

static void	get_uv(t_object *obj, t_vector ray, double *u, double *v)
{
	t_vector	local;
	t_vector	ulocal;
	double		costheta;

	local = vector_substract(obj->hit.normalize, ray);
	ulocal = local;
	normalization(&ulocal);
	costheta = dot_product(ulocal, vector_rotate_cw(obj->hit.normalize));
	*u = sqrt(dot_product(local, ulocal)) * costheta * 700;
	costheta = dot_product(ulocal, vector_rotate_ccw(obj->hit.normalize));
	*v = sqrt(dot_product(local, ulocal)) * costheta * 700;
}

t_rgb	patterns(t_object *obj, t_vector ray, t_minirt *minirt)
{
	double	u;
	double	v;
	t_rgb	rgb_texture;
	t_rgb	rgb_bump;

	get_uv(obj, ray, &u, &v);
	if (minirt->texture.img && minirt->apply_texture)
		rgb_texture = rgb_pattern(minirt->texture, u, v, 0.75);
	if (minirt->bump.img && minirt->apply_bump)
		rgb_bump = rgb_pattern(minirt->bump, u, v, 0.8);
	if (minirt->apply_texture == 1 && !minirt->apply_bump)
		return (rgb_brightness_adjust(rgb_texture, 0.6));
	else if (!minirt->apply_texture && minirt->apply_bump)
		return (multiply_rgbs(obj->rgb, rgb2gray(rgb_bump)));
	else if (minirt->apply_texture == 1 && minirt->apply_bump)
		return (multiply_rgbs(rgb_texture, rgb2gray(rgb_bump)));
	else
		return (obj->rgb);
}
