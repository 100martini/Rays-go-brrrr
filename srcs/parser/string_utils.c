/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:44:53 by wel-kass          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:55 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	longest(int fd)
{
	int		buff;
	char	character;
	int		len;
	int		max_strlen;

	buff = read(fd, &character, 1);
	len = 0;
	max_strlen = 0;
	while (buff)
	{
		len++;
		if (character == '\n')
		{
			if (len > max_strlen)
				max_strlen = len;
			len = 0;
		}
		buff = read(fd, &character, 1);
	}
	close(fd);
	return (max_strlen);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
