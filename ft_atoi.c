/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:04:45 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:39 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *s)
{
	long unsigned	ret;

	ret = 0;
	if (!s)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *s - 48;
		s++;
	}
	return (ret);
}
