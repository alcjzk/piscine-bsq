/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:35:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/31 23:27:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include "map.h"
# include <stdlib.h>

char	*ft_realloc(char *buf, size_t size_old, size_t size_new);

//	Reads from the fd to buf at most limit bytes, or until a newline or EOF
//	if met. On failure / EOF, the return is -1. On success returns the amount
//	of bytes read. If the limit was reached before a newline, the return
//	value will be limit + 1.
int		nread_line_validate(int fd, char *buf, int limit);

#endif