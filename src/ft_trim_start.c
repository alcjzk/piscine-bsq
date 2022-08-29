/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:33:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/22 20:41:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trim_start.h"

//	Returns true if the given character is a whitespace character. Equivalent
//	to isspace(3).
bool	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (true);
	if (c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

//	Trims whitespace (ft_is_space) from the start of the given string and
//	returns a pointer to the new starting point.
char	*ft_trim_start(char *str)
{
	while (ft_is_space(*str))
		str++;
	return (str);
}
