/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:25:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/30 16:57:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Use unsigned characters / shorts instead

#include "main.h"
#include "read_map.h"
#include "ft_atoi.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_strlen.h"
#include "ft_strcpy.h"

t_map_header	*read_map_header(int fd)
{
	char			buf[32]; // TODO: Actual max size for this?
	int				i;
	t_map_header	*header;
	size_t			bytes_read;

	i = 0;
	header = malloc(sizeof(t_map_header));
	header->width = 0;
	if (!header)
		return (NULL);
	bytes_read = read(fd, &buf[i], 1);
	while (bytes_read == 1)
	{
		if (buf[i] == '\n')
			break;
		bytes_read = read(fd, &buf[++i], 1);
	}
	if (bytes_read != 1)
		return (NULL);
	header->filler = buf[--i];
	header->obstacle = buf[--i];
	header->empty = buf[--i];
	buf[i] = '\0';
	if (!is_numeric(buf))
	{
		free(header);
		return (NULL);
	}
	header->height = ft_atoi(buf);
	// FIXME: Debug print
	printf(
		"[MAP HEADER] Obstacle: '%c', Empty: '%c', Filler: '%c', Height: '%i'\n",
	header->obstacle,
	header->empty,
	header->filler,
	header->height
	);
	return (header);
}

//	Returns true if the given string only contains numeric characters, false
//	otherwise.
bool	is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

//	Reads a map row of unknown size from the given fd and sets the value in h.
char	*read_map_row(t_map_header *header, int fd)
{
	// FIXME: i out of bounds
	char	buf[1024]; // TODO: This will hard-limit the width of the map??
	int		i;
	char	*row;
	char	*buffer;
	size_t	bytes_read;
	size_t	bytes_read_total;
	size_t	buffer_size;

	i = 0;
	buffer_size = sizeof(char) * ROW_BUFFER_SIZE;
	buffer = malloc(sizeof(char) * ROW_BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, &buffer[i], 1);
	bytes_read_total = bytes_read;
	while (buf[i] != '\n' && bytes_read == 1 && bytes_read_total)
	{
		bytes_read = read(fd, &buffer[++i], ROW_BUFFER_SIZE);
		bytes_read_total += bytes_read;
	}
	if (bytes_read != 1)
		return (NULL);
	buf[i] = '\0';
	header->width = bytes_read_total - 1;
	row = malloc(bytes_read_total);
	row = ft_strcpy(row, buffer);
	return (row);
}

//	Reads a map row from the given fd based on a previously set rowsize.
char	*read_map_row_exact(t_map_header *header, int fd)
{
	char	*row;
	int		bytes_read;

	row = malloc(header->width + 1);
	if (!row)
		return (NULL);
	bytes_read = read(fd, row, (header->width + 1));
	if (bytes_read != header->width + 1)
		return (NULL);
	row[header->width] = '\0';
	return (row);
}

t_map	*read_map(int fd)
{
	t_map			*map;
	char			*first_row;
	char			*next_row;
	int				i;
	char			buf[1];

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->header = read_map_header(fd);
	map->map = malloc(sizeof(void *) * map->header->height);
	map->map[i] = read_map_row(map->header, fd);
	if (!map->map[i++])
		return (NULL);
	while (i < map->header->height)
	{
		printf("a\n");
		map->map[i] = read_map_row_exact(map->header, fd);
		if (!map->map[i++])
			return (NULL);
	}
	return (map);
}
