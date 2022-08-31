/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:22:15 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:10:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map {
	char	**map;
	char	empty;
	char	obstacle;
	char	filler;
	int		height;
	int		width;
}	t_map;

typedef struct s_square {
	int	x;
	int	y;
	int	size;
}	t_square;

//	Fills the given square into the map.
void	fill_square(t_map *map, t_square *square);

//	Prints the map.
void	print_map(t_map *map);

#endif