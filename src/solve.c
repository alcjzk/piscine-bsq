/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:16:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:23:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include <stdlib.h>

t_square	*solve_map(t_map *map, int x, int y)
{
	t_square	*largest_square;

	largest_square = malloc(sizeof(t_square));
	largest_square->size = 0;
	if (!largest_square)
		return (NULL);
	if (square_from_origin(map, x, y, largest_square->size))
	{
		largest_square->x = x;
		largest_square->y = y;
		largest_square->size++;
	}
	while (seek_next_origin(map, &x, &y, largest_square->size))
	{
		if (square_from_origin(map, x, y, largest_square->size))
		{
			largest_square->x = x;
			largest_square->y = y;
			largest_square->size++;
		}
	}
	return (largest_square);
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
		if (distance < size + 1)
			return (false);
	}
	return (true);
}

//	Returns the distance to the previous obstacle (or edge of map) from the
//	given position.
int	distance_to_previous_obstacle(t_map *map, int x, int y)
{
	int	distance;

	distance = 0;
	while (map->map[y][x] != map->obstacle && x > 0)
	{
		x--;
		distance++;
	}
	return (distance);
}

//	Moves the given x & y pointers to the next origin that has a larger
//	distance from the previous obstacle than the given distance.
//	Returns true if a new origin was found, false otherwise.
bool	seek_next_origin(t_map *map, int *x, int *y, int distance)
{
	int	distance_from_obstacle;

	*x = 0;
	if (*x >= (map->width - 1))
		(*y)++;
	else
		(*x)++;
	distance_from_obstacle = distance_to_previous_obstacle(map, *x, *y);
	while (distance < map->height - *y)
	{
		while (*x < map->width)
		{
			if (map->map[*y][*x] == map->obstacle)
				distance_from_obstacle = 0;
			if (map->map[*y][*x] == map->empty)
				distance_from_obstacle++;
			if (distance_from_obstacle > distance)
				return (true);
			(*x)++;
		}
		*x = 0;
		(*y)++;
	}
	return (false);
}
