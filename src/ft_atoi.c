/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:41:08 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/29 16:40:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "ft_trim_start.h"
#include <stdbool.h>

// Converts the initial portion of the given string to an integer.
int	ft_atoi(char *str)
{
	bool	negative;
	int		n;

	n = 0;
	negative = false;
	str = ft_trim_start(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = true;
		str++;
	}
	n = ft_atoi_recursive(str, n);
	if (negative)
		n *= -1;
	return (n);
}

int	ft_atoi_recursive(char *str, int n)
{
	if (*str < '0' || *str > '9')
		return (n);
	if (n > 0)
		n *= 10;
	n += ((*str) - 48);
	return (ft_atoi_recursive(++str, n));
}
