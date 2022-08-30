/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:27:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/30 16:20:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H
# define ROW_BUFFER_SIZE 64
# include "main.h"
# include <stdbool.h>

//	Reads a map header from the given file descriptor.
t_map_header	*read_map_header(int fd);

//	Reads a map row of unknown size from the given fd and sets the value in h.
char			*read_map_row(t_map_header *header, int fd);

t_map			*read_map(int fd);

//	Returns true if the given string only contains numeric characters, false
//	otherwise.
bool			is_numeric(char *str);

#endif