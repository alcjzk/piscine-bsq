/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:21:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/29 17:01:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdbool.h>

typedef struct s_map {
	char			**map;
	t_map_header	*header;
}	t_map;

typedef struct s_map_header {
	char	empty;
	char	obstacle;
	char	filler;
	int		height;
	int		width;
}	t_map_header;

//	Reads a map header from the given fd.
t_map_header	*read_map_header(int fd);
//	Reads a map row of unknown size from the given fd and sets the value in h.
char			*read_map_row(t_map_header *header, int fd);
//	Reads a map row from the given fd based on a previously set rowsize.
char			*read_map_row_exact(t_map_header *header, int fd);

t_map			*read_map(int fd);

t_map	*read_fd(int fd);

t_map	*fill_map(t_map *map);

// bool	is_valid(t_chars *chars, char c);
bool	is_digit(char c);

#endif