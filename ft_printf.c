/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:07:28 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:22 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(void)
{
	if (g_syntax.type == 'd' || g_syntax.type == 'i')
		ft_putd();
	else if (g_syntax.type == 's')
		ft_puts();
	else if (g_syntax.type == 'x' || g_syntax.type == 'X')
		ft_putx();
	else if (g_syntax.type == 'p')
		ft_putp();
	else if (g_syntax.type == 'u')
		ft_putu();
	else
		ft_putc();
}

int			ft_printf(const char *s, ...)
{
	va_list pa;
	int		i;

	g_ret = 0;
	i = 0;
	va_start(pa, s);
	while (s[i])
	{
		if (s[i] != '%' && s[i])
			ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			ft_getflag((char *)&s[i + 1], pa);
			ft_convflag(pa);
			ft_print();
			ft_reset();
		}
		s[i] == '%' ? i += g_a : i++;
	}
	va_end(pa);
	return (g_ret);
}
