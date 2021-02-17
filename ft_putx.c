/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:11:34 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:30:52 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_numlenx(unsigned nb)
{
	int i;

	if (nb == 0 && g_syntax.point && !g_syntax.precesion)
		return (0);
	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	ft_putlowx(unsigned int nb)
{
	int len;
	int i;
	int a;
	int x;

	if (!g_numf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = ft_numlenx(nb);
	while (++i < len)
		a *= 16;
	while (a)
	{
		x = nb / a;
		if (x < 10)
			ft_putchar((nb / a) + 48);
		else
			ft_putchar((nb / a) + 87);
		nb %= a;
		a /= 16;
	}
}

static void	ft_putbigx(unsigned nb)
{
	int len;
	int i;
	int a;
	int x;

	if (!g_numf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = ft_numlenx(nb);
	while (++i < len)
		a *= 16;
	while (a)
	{
		x = nb / a;
		if (x < 10)
			ft_putchar((nb / a) + '0');
		else
			ft_putchar((nb / a) + 55);
		nb %= a;
		a /= 16;
	}
}

void		ft_putx(void)
{
	int i;
	int nb;

	nb = (unsigned)g_numf.value;
	i = 0;
	while (i++ < g_numf.bs)
		ft_putchar(' ');
	i = 0;
	while (i++ < g_numf.zeros)
		ft_putchar('0');
	if (g_syntax.type == 'x')
		ft_putlowx(nb);
	if (g_syntax.type == 'X')
		ft_putbigx(nb);
	i = 0;
	while (i++ < g_numf.as)
		ft_putchar(' ');
}
