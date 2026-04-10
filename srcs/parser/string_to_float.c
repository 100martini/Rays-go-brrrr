/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:49 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:51 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static float	ft_atof_get_sign(char *str, int *i)
{
	int		mult;

	mult = 1.0;
	if (str[*i] == '-')
		mult = -1.0;
	if (str[*i] == '-' || str[*i] == '+')
		*i += 1;
	return (mult);
}

static int	ft_atof_get_integer(char *str, int *i, \
	int *devider)
{
	int		integer;

	integer = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		integer *= 10;
		integer += str[*i] - '0';
		*devider *= 10;
		*i += 1;
	}
	if (str[*i] == '.')
		*i += 1;
	return (integer);
}
