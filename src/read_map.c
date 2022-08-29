/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:25:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/29 22:18:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			buf[32];
	int				i;
	t_map_header	*header;

	i = 0;
	header = malloc(sizeof(t_map_header));
	header->width = 0;
	if (!header)
		return (NULL);
	read(fd, &buf[i], 1);
	while (buf[i] != '\n') // FIXME: handle eof?
		read(fd, &buf[++i], 1);
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
	printf("HEIGHT: %i\n", header->height);
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

	i = 0;
	read(fd, &buf[i], 1);
	while (buf[i] != '\n') // FIXME: handle eof?
		read(fd, &buf[++i], 1);
	buf[i] = '\0';
	header->width = ft_strlen(buf);
	row = malloc(header->width + 1);
	row = ft_strcpy(row, buf);
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
