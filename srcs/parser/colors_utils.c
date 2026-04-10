/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:08 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/22 22:02:42 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	adjust_channel(int channel)
{
	int	tmp;

	if (channel > 255)
		tmp = 255;
	else if (channel < 0)
		tmp = 0;
	else
		tmp = channel;
	return (tmp);
}

t_rgb	ft_adjust_rgb(t_rgb color)
{
	t_rgb	tmp;

	tmp.r = adjust_channel(color.r);
	tmp.g = adjust_channel(color.g);
	tmp.b = adjust_channel(color.b);
	return (tmp);
}

int	ft_rgb2hex(char t, t_rgb color)
{
	return (t << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_rgb	parsing_colors(char *str, int i, t_scene *scene)
{
	t_rgb	color;
	char	separator;

	separator = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	color.r = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	count_separators(str, &i, &separator);
	color.g = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	count_separators(str, &i, &separator);
	if (!str[i] || str[i] < '0' || str[i] > '9')
		separator--;
	color.b = ft_atoi(&str[i]);
	while ((str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r')) \
	|| (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] || separator != 2)
		ft_error(RGB_FORMAT, scene);
	return (color);
}
