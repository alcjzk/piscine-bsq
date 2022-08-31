/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:26:52 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:04:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>

/*	Fills the given square into the map. */
void	fill_square(t_map *map, t_square *square)
{
	int	k;
	int	y;

	y = square->y;
	while (y < (square->y + square->size) && y <= map->height)
	{
		k = square->x - square->size + 1;
		while (k <= square->x)
		{
			map->map[y][k] = map->filler;
			k++;
		}
		y++;
	}
}

/*	Prints the map. */
void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		write(1, map->map[y], (map->width + 1));
		y++;
	}
}
