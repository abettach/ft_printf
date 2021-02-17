/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:11:18 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:30:58 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_numlenu(unsigned int nb)
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

static void	ft_putunsigned(unsigned int nb)
{
	int len;
	int i;
	int a;

	if (!g_numf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = ft_numlenu(nb);
	while (++i < len)
		a *= 10;
	while (a)
	{
		ft_putchar((nb / a) + 48);
		nb %= a;
		a /= 10;
	}
}

void		ft_putu(void)
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
	ft_putunsigned(nb);
	i = 0;
	while (i++ < g_numf.as)
		ft_putchar(' ');
}
