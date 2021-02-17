/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:10:50 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:08 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			numlenp(long unsigned nb)
{
	int i;

	if (g_pf.value == NULL && g_syntax.point && !g_syntax.precesion)
		return (0);
	if (g_pf.value == NULL)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	putlowx(long unsigned nb)
{
	int				len;
	int				i;
	long unsigned	a;
	long unsigned	x;

	if (!g_pf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = numlenp(nb);
	while (++i < len)
		a *= 16;
	while (a)
	{
		x = nb / a;
		if (x < 10)
			ft_putchar((nb / a) + '0');
		else
			ft_putchar((nb / a) + 87);
		nb %= a;
		a /= 16;
	}
}

void		ft_putp(void)
{
	int				i;
	long unsigned	c;

	i = 0;
	c = (long unsigned int)g_pf.value;
	while (i++ < g_pf.bs)
		ft_putchar(' ');
	i = 0;
	ft_putstr("0x");
	while (i++ < g_pf.zeros)
		ft_putchar('0');
	putlowx(c);
	i = 0;
	while (i++ < g_pf.as)
		ft_putchar(' ');
}
