/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:22:15 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 13:32:01 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "main.h"

typedef struct s_map_header {
	char	empty;
	char	obstacle;
	char	filler;
	int		height;
	int		width;
}	t_map_header;

typedef struct s_map {
	char	**map;
	char	empty;
	char	obstacle;
	char	filler;
	int		height;
	int		width;
}	t_map;

//	Fills the given square into the map.
void	fill_square(t_map *map, t_square *square);

//	Prints the map.
void	print_map(t_map *map);

#endif