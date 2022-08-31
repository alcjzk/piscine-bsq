/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:17:48 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:24:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map.h"
# include <stdbool.h>

t_square	*solve_map(t_map *map, int x, int y);

//	Returns true if a full square of the given size can be formed from the
//	given origin.
bool		square_from_origin(t_map *map, int x, int y, int size);

//	Returns the distance to the previous obstacle (or edge of map) from the
//	given position.
int			distance_to_previous_obstacle(t_map *map, int x, int y);

//	Moves the given x & y pointers to the next origin that has a larger
//	distance from the previous obstacle than the given distance.
//	Returns true if a new origin was found, false otherwise.
bool		seek_next_origin(t_map *map, int *x, int *y, int distance);

#endif