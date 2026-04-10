/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:59 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/22 21:26:49 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)b;
	i = 0;
	while (i < len)
		tmp[i++] = (char)c;
	return (b);
}

void	is_valid(char *str, int i, t_scene *scene)
{
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		ft_error(BAD_FORMAT, scene);
}

void	count_separators(char *str, int *i, char *separator)
{
	while (str[*i] == ' ' || ('\t' <= str[*i] && str[*i] <= '\r'))
		*i += 1;
	if (str[*i] == ',')
	{
		*separator += 1;
		*i += 1;
	}
	while (str[*i] == ' ' || ('\t' <= str[*i] && str[*i] <= '\r'))
		*i += 1;
}

t_vector	parsing_vectors(char *str, int *i, t_scene *scene)
{
	t_vector	matrix;
	char		separator;

	separator = 0;
	while (str[*i] == ' ' || ('\t' <= str[*i] && str[*i] <= '\r'))
		*i += 1;
	matrix.x = ft_atof(str, i);
	count_separators(str, i, &separator);
	matrix.y = ft_atof(str, i);
	count_separators(str, i, &separator);
	matrix.z = ft_atof(str, i);
	if (separator != 2)
		ft_error(VECTOR_FORMAT, scene);
	return (matrix);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	char	*ptr;

	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	i = 0;
	ptr = NULL;
	while ((len - i) >= n_len && !ptr)
	{
		if (!ft_strncmp(haystack + i, needle, n_len))
			ptr = (char *)(haystack + i);
		if (haystack[i] == '\0')
			break ;
		i++;
	}
	return (ptr);
}
