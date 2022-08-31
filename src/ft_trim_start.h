/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_start.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:44 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/22 20:41:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRIM_START_H
# define FT_TRIM_START_H
# include <stdbool.h>

//	Returns true if the given character is a whitespace character. Equivalent
//	to isspace(3).
bool	ft_is_space(char c);

//	Trims whitespace (ft_is_space) from the start of the given string and
//	returns a pointer to the new starting point.
char	*ft_trim_start(char *str);

#endif