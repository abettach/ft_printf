/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:14:37 by abettach          #+#    #+#             */
/*   Updated: 2020/02/28 12:17:46 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_syntax
{
	char	flag;
	int		width;
	char	point;
	int		precesion;
	char	length;
	char	type;
}				t_syntax;

typedef struct	s_numf
{
	int value;
	int bs;
	int as;
	int zeros;
}				t_numf;

typedef struct	s_cf
{
	char	value;
	int		bs;
	int		as;
	int		zeros;
}				t_cf;

typedef struct	s_sf
{
	char	*value;
	int		bs;
	int		as;
	int		zeros;
}				t_sf;

typedef struct	s_pf
{
	void	*value;
	int		bs;
	int		as;
	int		zeros;
}				t_pf;

int				g_ret;
int				g_a;
char			g_error;
t_syntax		g_syntax;
t_pf			g_pf;
t_numf			g_numf;
t_cf			g_cf;
t_sf			g_sf;

int				ft_printf (const char *format, ...);
void			ft_putchar(char c);
int				ft_numlen(int nb);
int				ft_atoi(char *s);
void			ft_putstr(char *str);
int				is_set(char c, char *set);
void			ft_putp(void);
void			ft_reset(void);
void			ft_getflag(char *s, va_list pa);
int				ft_numlenx(unsigned nb);
void			ft_convflag(va_list pa);
int				ft_max(int a, int b);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *str);
void			ft_puts(void);
void			ft_putc(void);
void			ft_putd(void);
void			ft_putx(void);
int				ft_numlenu(unsigned int nb);
void			ft_putu(void);
void			ft_putp(void);
int				ft_min(int a, int b);
void			ft_intconv(va_list pa);
void			ft_uconv(va_list pa);
void			ft_xconv(va_list pa);
void			ft_pconv(va_list pa);
void			ft_sconv(va_list pa);
void			ft_cconv(va_list pa);
int				numlenp(long unsigned nb);

#endif
