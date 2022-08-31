/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:26:52 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 13:40:38 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*	Fills the given square into the map. */
void	fill_square(t_map *map, t_square *square)
{
	int	k;
	int	y;

	y = solved_square->y;
	while (y < (solved_square->y + solved_square->size)
		&& y <= map->header->height)
	{
		k = solved_square->x - solved_square->size + 1;
		while (k <= solved_square->x)
		{
			map->map[y][k] = map->header->filler;
			k++;
		}
	y++;
	}
	print_map(map);
}

/*	Prints the map. */
void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (y <= map->header->height)
	{
		write(1, map->map[y], map->header->width);
		write(1, "\n", 1);
		y++;
	}
}
