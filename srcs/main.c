/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:45:08 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/22 22:43:25 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	main(int argc, char **argv)
{
	t_scene		scene;
	int			fd;

	if (argc != 2)
		ft_error(NO_ARGS, 0);
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		ft_error(NO_ARGS, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(ERR_FILE, 0);
	ft_memset(&scene, 0, sizeof(t_scene));
	parsing_scene(fd, longest(open(argv[1], O_RDONLY)), &scene);
	prepare_scene(&scene);
	graphics(&scene);
	return (0);
}
