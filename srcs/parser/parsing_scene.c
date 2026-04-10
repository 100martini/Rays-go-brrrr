/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:23 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/22 21:25:30 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	assets(t_scene *scene, char *str, int i)
{
	if (str[i] == 'A')
		ambient(scene, str, i + 1);
	else if (str[i] == 'C')
		camera(scene, str, i + 1);
	else if (str[i] == 'L')
	{
		light(scene, str, i + 1);
		light_as_objects(scene, scene->light);
	}
}

static void	objects(t_scene *scene, char *str, int i)
{
	if (!scene->object)
		scene->object = init_object(scene);
	else
	{
		scene->object->next = init_object(scene);
		scene->object->next->previous = scene->object;
		scene->object = scene->object->next;
	}
	if (str[i] == 's' && str[i + 1] == 'p')
		sphere(scene, str, i + 2);
	else if (str[i] == 'p' && str[i + 1] == 'l')
		plane(scene, str, i + 2);
	else if (str[i] == 'c' && str[i + 1] == 'y')
		cylinder(scene, str, i + 2);
	else if (str[i] == 'c' && str[i + 1] == 'o')
		cone(scene, str, i + 2);
}

static void	parsing_elements(t_scene *scene, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i + 1] && str[i + 1] == ' '
		&& (str[i] == 'A' || str[i] == 'C' || str[i] == 'L'))
		assets(scene, str, i);
	else if (str[i + 2] && str[i + 2] == ' '
		&& ((str[i] == 's' && str[i + 1] == 'p')
			|| (str[i] == 'p' && str[i + 1] == 'l')
			|| (str[i] == 'c' && str[i + 1] == 'y')
			|| (str[i] == 'c' && str[i + 1] == 'o')))
		objects(scene, str, i);
	else
	{
		free(str);
		ft_error(BAD_FORMAT, scene);
	}
}

static char	*get_line(int size)
{
	char	*line;

	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		ft_error(MALLOC_LINE, 0);
	ft_memset(line, 0, size + 1);
	return (line);
}

void	parsing_scene(int fd, int longest, t_scene *scene)
{
	int		buff;
	char	character;
	char	*line;
	int		i;

	line = get_line(longest);
	buff = 1;
	i = 0;
	while (buff)
	{
		buff = read(fd, &character, 1);
		if (character != '\n')
			line[i++] = character;
		else
		{
			line[i] = 0;
			if (i)
				parsing_elements(scene, line);
			i = 0;
		}
	}
	free(line);
	close(fd);
}
