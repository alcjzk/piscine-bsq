/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:25:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:29:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include "ft_atoi.h"
#include <unistd.h>
#include "read.h"
#include "ft_string.h"

t_map	*map_header_from_buffer(char *buf, int size)
{
	t_map			*map;
	int				i;

	i = size - 1;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (size < 5)
		return (NULL);
	map->filler = buf[--i];
	map->obstacle = buf[--i];
	map->empty = buf[--i];
	buf[i] = '\0';
	if (!is_numeric(buf))
		return (NULL);
	map->height = ft_atoi(buf);
	if (map->height <= 0)
		return (NULL);
	return (map);
}

//	Reads a map header from the given file descriptor.
t_map	*read_map_header(int fd)
{
	char			buf[32];
	int				i;
	size_t			bytes_read;

	i = 0;
	bytes_read = 1;
	while (bytes_read == 1 && i < 32)
	{
		bytes_read = read(fd, &buf[i], 1);
		if (buf[i++] == '\n')
			break ;
	}
	if (bytes_read != 1 || i >= 32)
		return (NULL);
	return (map_header_from_buffer(buf, i));
}

//	Reads a map row of unknown size from the given fd and sets the value in h.
char	*read_map_row(t_map *map, int fd)
{
	size_t	i;
	char	*buffer;
	size_t	bytes_read;
	size_t	buffer_size;

	i = 0;
	buffer_size = 0;
	bytes_read = 0;
	while (i == 0 || buffer[i - 1] != '\n')
	{
		if (i >= buffer_size)
		{
			buffer = ft_realloc(buffer, buffer_size, buffer_size + 512);
			if (!buffer)
				return (NULL);
			buffer_size += 512;
		}
		bytes_read = nread_line_validate(fd, &buffer[i], buffer_size);
		if (bytes_read <= 0)
			return (NULL);
		i += bytes_read;
	}
	map->width = i - 1;
	return (ft_realloc(buffer, i, i));
}

//	Reads a map row from the given fd based on a previously set rowsize.
char	*read_map_row_exact(t_map *map, int fd)
{
	char	*row;
	int		bytes_read;

	row = malloc(map->width + 1);
	if (!row)
		return (NULL);
	bytes_read = read(fd, row, (map->width + 1));
	if (bytes_read != map->width + 1)
		return (NULL);
	row[map->width] = '\n';
	return (row);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	int		i;

	map = read_map_header(fd);
	if (!map)
		return (NULL);
	i = 0;
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		return (NULL);
	map->map[i] = read_map_row(map, fd);
	if (!map->map[i++])
		return (NULL);
	while (i < map->height)
	{
		map->map[i] = read_map_row_exact(map, fd);
		if (!map->map[i++])
			return (NULL);
	}
	return (map);
}
