/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:25 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:28 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	get_rgb(int r, int g, int b)
{
	t_rgb	tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	return (tmp);
}

t_rgb	rgb2gray(t_rgb rgb)
{
	unsigned char	gray;

	gray = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
	return (get_rgb(gray, gray, gray));
}

t_rgb	rgb_brightness_adjust(t_rgb rgb, float adjust)
{
	rgb.r *= adjust;
	rgb.g *= adjust;
	rgb.b *= adjust;
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}
