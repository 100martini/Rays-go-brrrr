/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:14 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:15 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void	normalization(t_vector *vect)
{
	float	len;

	len = vector_len(*vect);
	if (!len)
	{
		vect->x = 0;
		vect->y = 0;
		vect->z = 0;
	}
	else
	{
		vect->x /= len;
		vect->y /= len;
		vect->z /= len;
	}
}

float	dot_product(t_vector v1, t_vector v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

float	point_dist(t_vector v1, t_vector v2)
{
	float	res;

	res = sqrtf((v2.x - v1.x) * (v2.x - v1.x)
			+ (v2.y - v1.y) * (v2.y - v1.y)
			+ (v2.z - v1.z) * (v2.z - v1.z));
	return (res);
}
