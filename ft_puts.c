/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:11:04 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:04 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_puts(void)
{
	int i;

	i = 0;
	while (i++ < g_sf.bs)
		ft_putchar(' ');
	while (i++ <= g_sf.zeros)
		ft_putchar('0');
	i = 0;
	if (!g_syntax.point)
	{
		ft_putstr(g_sf.value);
		while (i++ < g_sf.as)
			ft_putchar(' ');
	}
	else
	{
		while ((i < g_syntax.precesion) && g_sf.value[i])
			ft_putchar(g_sf.value[i++]);
		i = 0;
		while (i++ < g_sf.as)
			ft_putchar(' ');
	}
}
