/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:27:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:08:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H
# include "map.h"

t_map	*map_header_from_buffer(char *buf, int size);

//	Reads a map header from the given file descriptor.
t_map	*read_map_header(int fd);

//	Reads a map row of unknown size from the given fd and sets the value in h.
char	*read_map_row(t_map *map, int fd);

//	Reads a map row from the given fd based on a previously set rowsize.
char	*read_map_row_exact(t_map *map, int fd);

t_map	*read_map(int fd);

#endif