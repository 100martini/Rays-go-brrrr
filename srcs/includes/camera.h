/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:31 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:32 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_vector	t_vector;

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		angle;
}				t_camera;

t_camera	*create_camera(t_vector *org, t_vector *dir, float angle);

#endif
