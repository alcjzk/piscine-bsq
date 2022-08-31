/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:35:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <unistd.h>

char	*ft_realloc(char *buf, size_t size_old, size_t size_new)
{
	char	*new_buffer;
	size_t	i;

	new_buffer = malloc(size_new);
	if (!new_buffer)
		return (NULL);
	i = 0;
	if (size_old != 0)
	{
		while (i < size_old)
		{
			new_buffer[i] = buf[i];
			i++;
		}
		free(buf);
	}
	return (new_buffer);
}

//	Reads from the fd to buf at most limit bytes, or until a newline or EOF
//	if met. On failure / EOF, the return is -1. On success returns the amount
//	of bytes read. If the limit was reached before a newline, the return
//	value will be limit + 1.
int	nread_line_validate(int fd, char *buf, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		if (read(fd, &buf[i], 1) != 1)
			return (-1);
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (limit);
}
