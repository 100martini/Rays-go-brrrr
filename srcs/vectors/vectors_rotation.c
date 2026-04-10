/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:11 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:12 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//Clockwise Rotation (Component Swap) (x, y, z) → (z, x, y)
t_vector	vector_rotate_cw(t_vector vector)
{
	float	tmp;

	tmp = vector.z;
	vector.z = vector.y;
	vector.y = vector.x;
	vector.x = tmp;
	return (vector);
}

//Counter-Clockwise Rotation  (Reverse Swap) (x, y, z) → (y, z, x)
t_vector	vector_rotate_ccw(t_vector vector)
{
	float	tmp;

	tmp = vector.x;
	vector.x = vector.y;
	vector.y = vector.z;
	vector.z = tmp;
	return (vector);
}
