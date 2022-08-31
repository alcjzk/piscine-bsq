/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:21:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/30 20:56:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdbool.h>

typedef struct s_map_header {
	char	empty;
	char	obstacle;
	char	filler;
	int		height;
	int		width;
}	t_map_header;

typedef struct s_map {
	char			**map;
	t_map_header	*header;
}	t_map;

typedef struct s_square {
	int	x;
	int	y;
	int size;
}	t_square;

t_square	*solve_map(t_map *map);
int			test_cube(t_map *main_map, int y, int x, int k);

t_map	*read_fd(int fd);

t_map	*fill_map(t_map *map);

// bool	is_valid(t_chars *chars, char c);
bool	is_digit(char c);

//	Moves the given x & y pointers to the next origin that has a larger
//	distance from the previous obstacle than the given distance.
//	Returns true if a new origin was found, false otherwise.
bool	seek_next_origin(t_map *map, int *x, int *y, int distance);

//	Returns the distance to the previous obstacle (or edge of map) from the
//	given position.
int		distance_to_previous_obstacle(t_map *map, int x, int y);

//	Returns true if a full square of the given size can be formed from the
//	given origin.
bool	square_from_origin(t_map *map, int x, int y, int size);

#endif