/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:53:51 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 13:31:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_atoi.h"
#include "read_map.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_square	*square;

	printf("HELLO\n");

	fd = open("testing.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open file!\n");
		return (1);
	}
	map = read_map(fd);
	if (!map)
	{ 
		printf("Failed to read map!\n");
		return (1);
	}
	printf("Map x: %i, y: %i\n", map->header->width, map->header->height);
	square = solve_map(map , map->header, 0, 0);
	if (!square)
	{
		printf("Failed to solve!\n");
		return (1);
	}
	printf("biggest square has size:%d and is at %d,%d\n",
		square->size,
		square->x,
		square->y
	);
	return (0);
}

bool	run(int argc, char **argv)
{
	int			i;
	t_map		*map;
	t_square	*largest_square;

	if (argc <= 1)
	{
		// Stdin
		if (!handle_file(STDIN_FILENO))
		{
			printf("Map error\n"); // TODO: Replace with some putstr
			return (1);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!handle_file(open(argv[i], O_RDONLY)))
			{
				printf("Map error\n"); // TODO: Replace with some putstr
			}
		}
		return (0);
	}
}

bool	handle_file(int fd)
{
	t_map		*map;
	t_square	*largest_square;
	if (fd < 0)
		return (false);
	map = read_map(map);
	if (!map)
		return (false);
	largest_square = solve_map(map);
	if (!largest_square)
		return (false);
	// TODO: Print largest square
	return (true);
}

//	Moves the given x & y pointers to the next origin that has a larger
//	distance from the previous obstacle than the given distance.
//	Returns true if a new origin was found, false otherwise.
bool	seek_next_origin(t_map *map, int *x, int *y, int distance)
{
	int	available_height;
	int	map_height;
	int	map_width;
	int	distance_from_obstacle;

	map_width = map->header->width;
	map_height = map->header->height;
	if (*x >= map_width)
	{
		*x = 0;
		(*y)++;
	}
	else
		*x++;
	distance_from_obstacle = distance_to_previous_obstacle(map, x, y);
	available_height = map->header->height - *y;
	while (distance < available_height)
	{
		while (*x < map_width)
		{
			if (map->map[*x][*y] == map->header->obstacle)
				distance_from_obstacle = 0;
			if (map->map[*x][*y] == map->header->empty)
				distance_from_obstacle++;
			if (distance_from_obstacle > distance)
				return (true);
			(*x)++;
		}
		*x = 0;
		(*y)++;
		available_height--;
	}
	return (false);
}

//	Returns the distance to the previous obstacle (or edge of map) from the
//	given position.
int		distance_to_previous_obstacle(t_map *map, int x, int y)
{
	int	distance;

	distance = 0;
	while (map->map[x][y] != map->header->obstacle && x > 0)
	{
		x--;
		distance++;
	}
	return (distance);
}

//	Returns true if a full square of the given size can be formed from the
//	given origin.
bool	square_from_origin(t_map *map, int x, int y, int size)
{
	int	i;
	int	distance;

	i = 0;
	distance = 0;
	if (size == 1)
		return (true);
	while (i < size)
	{
		i++;
		y++;
		distance = distance_to_previous_obstacle(map, x, y);
		if (distance < size)
			return (false);
	}
	return (true);
}

t_square	*solve_map(t_map *map)
{
	int	x;
	int	y;
	t_square	*largest_square;

	largest_square = malloc(sizeof(t_square));
	largest_square->size = 0;
	if (!largest_square)
		return (NULL);
	x = 0;
	y = 0;
	while (seek_next_origin(map, &x, &y, largest_square->size))
	{
		if (square_from_origin(map, x, y, largest_square->size))
		{
			largest_square->x = x;
			largest_square->y = y;
			largest_square->size++;
		}
	}
}

// t_square	*solve_map(t_map *map, int d, int y, int x) //had to use "d" to save space for norminette but d is the number of empty spaces after previous obsticle
// {
// 	t_square	*square;
// 	int			x;
// 	int			y;
// 	int			available_height;

// 	x = 0;
// 	y = 0;
// 	available_height = map->header->height;
// 	map = map->map;
// 	square = malloc(sizeof(t_square));
// 	if (!square)
// 		return (NULL);


// 	while (y <= map->header->height && (s->size) < (map->header->height - y))
// 	{
// 		x = 0;
// 		d = 0;
// 		while (x < map->header->width)
// 		{				
// 			if (map->map[y][x] != map->header->obstacle && map->map[y][x] != map->header->empty && map->map[y][x] != '\0')
// 				return (NULL);
// 			if (map->map[y][x] == map->header->obstacle)
// 					d = 0;
// 			if (map->map[y][x] == map->header->empty)
// 				d++;
// 			if (d > s->size && (s->size) < (map->header->height - y) && (test_cube(map, y, x, s->size)))
// 				s = new_s(y, x, s->size);
// 		x++;
// 		}
// 	y++;
// 	}
// 	return (s);
// }

// int	test_cube(t_map *map, int y, int x, int k)
// {
// 	int	i;
// 	int	n;

// 	i = 0;
// 	while (i <= k)
// 	{
// 		n = 0;
// 		while (n <= k)
// 		{
// 			if (map->map[y + i][x - n] != map->header->empty)
// 			{
// 				return (0);
// 			}
// 			n++;
// 		}
// 	i++;
// 	}
// 	return (1);
// }

// t_square	*new_s(int y, int x, int size)
// {
// 	t_square	*new_s;

// 	new_s = malloc(sizeof(t_square));
// 	if (!new_s)
// 		return (NULL);
// 	new_s->x = x;
// 	new_s->y = y;
// 	new_s->size = size + 1;
// 	return (new_s);
// }