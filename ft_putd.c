/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:10:31 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:11 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_numlen(int nb)
{
	int i;

	if (nb == 0 && g_syntax.point && !g_syntax.precesion)
		return (0);
	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(int nb)
{
	int		len;
	int		i;
	long	nbr;
	int		a;

	if (!g_numf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = ft_numlen(nb);
	while (++i < len)
		a *= 10;
	nbr = (long)nb;
	if (nb < 0)
		nbr = -nbr;
	while (a)
	{
		ft_putchar((nbr / a) + '0');
		nbr %= a;
		a /= 10;
	}
}

void		ft_putd(void)
{
	int i;
	int nb;

	nb = g_numf.value;
	i = 0;
	while (i++ < g_numf.bs)
		ft_putchar(' ');
	if (g_numf.value < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (i++ < g_numf.zeros)
		ft_putchar('0');
	ft_putnbr(nb);
	i = 0;
	while (i++ < g_numf.as)
		ft_putchar(' ');
}
