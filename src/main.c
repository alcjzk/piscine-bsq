/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:53:51 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:39:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "read.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_atoi.h"
#include "solve.h"
#include "read_map.h"

#include "ft_string.c"
#include "ft_strlen.c" // FIXME
#include "ft_trim_start.c"
#include "map.c"
#include "read_map.c"
#include "read.c"
#include "solve.c"
#include "ft_atoi.c"

int	main(int argc, char **argv)
{
	if (!run(argc, argv))
		return (1);
	return (0);
}

bool	run(int argc, char **argv)
{
	int			i;

	if (argc <= 1)
	{
		if (!handle_file(STDIN_FILENO))
		{
			write(1, "map error\n", 10);
			return (false);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!handle_file(open(argv[i], O_RDONLY)))
				write(1, "map error\n", 10);
			write(1, "\n", 1);
			i++;
		}
	}
	return (true);
}

bool	handle_file(int fd)
{
	t_map		*map;
	t_square	*largest_square;
	int			i;

	if (fd < 0)
		return (false);
	map = read_map(fd);
	if (!map)
		return (false);
	largest_square = solve_map(map, 0, 0);
	if (!largest_square)
		return (false);
	fill_square(map, largest_square);
	print_map(map);
	i = 0;
	while (i < map->height)
		free(map->map[i]);
	free(map->map);
	free(map);
	return (true);
}
