/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:35:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 20:51:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include "map.h"

// typedef struct s_map_header {
// 	char	empty;
// 	char	obstacle;
// 	char	filler;
// 	int		height;
// 	int		width;
// }	t_map_header;

t_map	*map_from_buffer(char *buf, int size);

//	Reads a map header from the given file descriptor.
t_map	*read_map_header(int fd);

//	Reads a map row of unknown size from the given fd and sets the value in h.
char			*read_map_row(t_map *map, int fd);

//	Reads a map from the given file descriptor.
t_map			*read_map(int fd);

int	nread_line_validate(int fd, char *buf, int limit, t_map *map);

#endif