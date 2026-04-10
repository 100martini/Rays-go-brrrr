/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:47 by mmanaoui          #+#    #+#             */
/*   Updated: 2025/04/21 16:55:48 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define COLOR_ERROR "\033[31m"
# define TC_OK "\033[32m"
# define COLOR_END "\033[0m"

# define NO_ARGS "Usage: ./miniRT scenes/scene.rt"
# define BAD_FORMAT "Incorrect formatting of the scene description file"
# define RGB_FORMAT "Incorrect RGB color formatting"
# define VECTOR_FORMAT "Incorrect vector formatting"

# define ERR_FILE "Failed to open scene description file"

# define AMBIENT_DECL "Ambient is already declared in the scene"
# define AMBIENT_NDECL "No ambient is declared in the scene"
# define AMBIENT_LIGHT "Ambient lighting ratio not in [0, 1]"
# define AMBIENT_COLOR "Ambient R,G,B colors not in [0, 255]"

# define CAMERA_DECL "Camera is already declared in the scene"
# define CAMERA_NDECL "No camera is declared in the scene"
# define CAMERA_ORIENT "Camera x,y,z orientation vector not in [-1, 1]"
# define CAMERA_NNORM "Camera orientation vector not normalized"
# define CAMERA_FOV "Camera horizontal fow not in [0, 180]"

# define LIGHT_DECL "Light is already declared in the scene"
# define LIGHT_NDECL "No light is declared in the scene"
# define LIGHT_BRIGHT "Light brightness ratio not in [0, 1]"
# define LIGHT_COLOR "Light R,G,B colors not in [0, 255]"

# define OBJECT_NDECL "No object is declared in the scene"

# define SPHERE_COLOR "Sphere R,G,B colors not in [0, 255]"

# define PLANE_ORIENT "Plane x,y,z orientation vector not in [-1, 1]"
# define PLANE_NNORM "Plane orientation vector not normalized"
# define PLANE_COLOR "Plane R,G,B colors not in [0, 255]"

# define CLND_ORIENT "Cylinder x,y,z orientation vector not in [-1, 1]"
# define CLND_NNORM "Cylinder orientation vector not normalized"
# define CLND_COLOR "Cylinder R,G,B colors not in [0, 255]"

# define CONE_ORIENT "Cone x,y,z orientation vector not in [-1, 1]"
# define CONE_NNORM "Cone orientation vector not normalized"
# define CONE_COLOR "Cone R,G,B colors not in [0, 255]"

# define MALLOC_LINE "Failed to allocate memory for line"
# define MALLOC_SCENE "Failed to allocate memory for scene"
# define MALLOC_LIGHT "Failed to allocate memory for light"
# define MALLOC_OBJECT "Failed to allocate memory for object"
# define MALLOC_LGHT_ARR "Failed to allocate memory for lights array"
# define MALLOC_OBJS_ARR "Failed to allocate memory for objects array"
# define MALLOC_VIEW "Failed to allocate memory for view"

# define ERR_MALLOC "Error\nMemory allocation failed\n"
# define ERR_ARGS "Error\nWrong # of arguments: ./fdf map_file\n"
# define ERR_MAP "Error\nBad formatting of the map_file\n"
# define ERR_READING "Error\nCannot read the map_file\n"
# define ERR_FD_OPEN "Error\nCould not open the map_file\n"
# define ERR_FD_CLOSE "Error\nCould not close the map_file\n"
# define ERR_IS_DIR "Error\nThe file is a directory, not a map\n"
# define ERR_MLX "Error\nMLX initiation failed\n"
# define ERR_WIN "Error\nWindow initiation failed\n"
# define ERR_IMG "Error\nError on image initiation\n"

# define SUCCES 0
# define ERROR_FILE_OPEN 1

# define ERROR_MALLOC_LINE 2
# define ERROR_MALLOC_AMBIENT 3
# define ERROR_MALLOC_CAMERA 4
# define ERROR_MALLOC_CAMERA_ORIGIN 5
# define ERROR_MALLOC_CAMERA_DIRECTION 6
# define ERROR_MALLOC_LIGHT 7
# define ERROR_MALLOC_LIGHT_ORIGIN 8
# define ERROR_MALLOC_OBJECTS_LIST 9

# define ERROR_MALLOC "Error\nMemory allocation failed\n"

# include "prototypes.h"

typedef struct s_scene	t_scene;

void					free_scene(t_scene *scene);
void					ft_error(char *typerr, t_scene *scene);
void					ft_error02(char *typerr, t_vector *normalize);
#endif
