/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:53:51 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/29 16:41:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_atoi.h"

// typedef struct s_map {
// 	char	**map;
// 	char	empty;
// 	char	obstacle;
// 	char	filler;
// 	int		rows;
// }	t_map;

t_map_header	*read_map_header(int fd)
{
	char	buf[32];
	int		i;
	char	filler;
	char	empty;
	char	obstacle;
	int		rows;

	i = 0;
	read(STDIN_FILENO, &buf[i++], 1);
	while (buf[i] != '\n')
		read(STDIN_FILENO, &buf[i++], 1);
	i--;
	filler = buf[i--];
	obstacle = buf[i--];
	empty = buf[i];
	buf[i] = '\0';
	rows = ft_atoi(buf);
}


// t_map	*read_fd(int fd)
// {
// 	char		buf[512];
// 	size_t		bytes_read;
// 	size_t		size_total;
// 	char		*map;

// }

int	main(int argc, char **argv)
{
	return (0);
}
