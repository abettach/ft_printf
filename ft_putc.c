/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:14:23 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:14 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_ret++;
}

void	ft_putc(void)
{
	int i;

	i = 0;
	while (i++ < g_cf.zeros)
		ft_putchar('0');
	while (i++ <= g_cf.bs)
		ft_putchar(' ');
	ft_putchar(g_cf.value);
	while (i++ <= g_cf.as + 1)
		ft_putchar(' ');
}
