/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:53:58 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:59 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	offscreen(int x, int y)
{
	if (x < 0 || x >= WIN_WIDTH)
		return (1);
	if (y < 0 || y >= WIN_HEIGHT)
		return (1);
	return (0);
}

void	pixel_put(t_minirt *minirt, int x, int y, int color)
{
	char	*dst;

	if (offscreen(x, y))
		return ;
	dst = minirt->addr + (y * minirt->line_length
			+ x * (minirt->bits_per_pixel));
	*(unsigned int *)dst = color;
}
