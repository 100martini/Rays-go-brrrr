/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:08 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:09 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../includes/minirt.h"

t_vector	vector_substract(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	vect_mult(t_vector vect, float n)
{
	t_vector	res;

	res.x = vect.x * n;
	res.y = vect.y * n;
	res.z = vect.z * n;
	return (res);
}

t_vector	vect_div(t_vector vect, float n)
{
	t_vector	res;

	res.x = vect.x / n;
	res.y = vect.y / n;
	res.z = vect.z / n;
	return (res);
}

float	vector_len(t_vector vect)
{
	float	res;

	res = sqrt(dot_product(vect, vect));
	return (res);
}
