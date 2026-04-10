/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:56:18 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:56:19 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "prototypes.h"

/* scene_inits */
t_light		*init_light(t_scene *scene);
t_object	*init_object(t_scene *scene);
t_light		**lights_init(int i, t_scene *scene);
t_object	**ft_objects_init(int i, t_scene *scene);

/* scene_preparation */
void		prepare_scene(t_scene *scene);
void		camera_rotation(t_scene *scene);

/* scene_utilities */
t_light		**convert_lights2arr(t_scene *scene);
t_object	**convert_objects2arr(t_scene *scene);
void		light_as_objects(t_scene *scene, t_light *light);

//parsing_scene.c
void		parsing_scene(int fd, int longest, t_scene *scene);

//assets.c
char		colors(t_rgb c);
char		orientation(t_vector v);
void		ambient(t_scene *scene, char *str, int i);
void		camera(t_scene *scene, char *str, int i);
void		light(t_scene *scene, char *str, int i);

//objects.c
void		sphere(t_scene *scene, char *str, int i);
void		plane(t_scene *scene, char *str, int i);
void		cylinder(t_scene *scene, char *str, int i);
void		cone(t_scene *scene, char *str, int i);

//utilities.c
void		is_valid(char *str, int i, t_scene *scene);
void		count_separators(char *str, int *i, char *separator);
t_vector	parsing_vectors(char *str, int *i, t_scene *scene);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_memset(void *b, int c, size_t len);

//utilities_atoi_atof.c
int			ft_atoi(const char *str);
float		ft_atof(char *str, int *i);

//utilities_color.c
t_rgb		ft_adjust_rgb(t_rgb color);
int			ft_rgb2hex(char t, t_rgb color);
t_rgb		get_rgb(int r, int g, int b);
t_rgb		parsing_colors(char *str, int i, t_scene *scene);

//utilities_string.c
size_t		ft_strlen(const char *s);
int			longest(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
