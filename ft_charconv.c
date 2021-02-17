/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:05:10 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:34 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sconv(va_list pa)
{
	int	len;

	g_sf.value = ft_strdup(va_arg(pa, char *));
	if (!g_sf.value)
		g_sf.value = ft_strdup("(null)");
	len = ft_strlen(g_sf.value);
	if (g_syntax.flag == '0' && g_syntax.point)
		g_sf.zeros = g_syntax.width - ft_min(g_syntax.precesion, len);
	if (g_syntax.flag == '0' && !g_syntax.point)
		g_sf.zeros = g_syntax.width - len;
	else if (g_syntax.flag == '-' && g_syntax.point)
		g_sf.as = g_syntax.width - ft_min(g_syntax.precesion, len);
	else if (g_syntax.flag == '-' && !g_syntax.point)
		g_sf.as = g_syntax.width - len;
	else if (!g_syntax.flag && g_syntax.point)
		g_sf.bs = g_syntax.width - ft_min(g_syntax.precesion, len);
	else if (!g_syntax.flag && !g_syntax.point)
		g_sf.bs = g_syntax.width - len;
}

void	ft_cconv(va_list pa)
{
	if (g_syntax.type == 'c')
		g_cf.value = (char)(va_arg(pa, int));
	else
		g_cf.value = g_syntax.type;
	if (g_syntax.flag == '0')
		g_cf.zeros = g_syntax.width - 1;
	else if (g_syntax.flag == '-')
		g_cf.as = g_syntax.width - 1;
	else if (!g_syntax.flag)
		g_cf.bs = g_syntax.width - 1;
}
