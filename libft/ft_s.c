/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_s_x_r(t_pf *f, char *str, int flag)
{
	if (flag == 1)
		f->t.tmp[f->t.y] = '\0';
	f->t.len = ft_strlen(str);
	if (f->t.len >= f->t.x)
		f->t.res += ft_putstr(str);
	else
	{
		f->t.x -= f->t.len;
		f->t.res += ft_putstr(str);
		while (f->t.i < f->t.x)
		{
			f->t.res += ft_putchar(' ');
			f->t.i += 1;
		}
	}
	return (0);
}

void		ft_s_x_dat(t_pf *f, char *str)
{
	f->t.tmp = ft_strdup(str);
	f->t.len = ft_strlen(str);
	if (f->t.y >= f->t.len && f->t.x <= f->t.len)
		f->t.res += ft_putstr(str);
	else if (f->t.x <= f->t.y)
		ft_s_dat(f, str);
	else if (f->t.x > f->t.len && f->t.m == 0)
		ft_s_x(f, f->t.tmp, 1);
	else if (f->t.x > f->t.len && f->t.m == 1)
		ft_s_x_r(f, f->t.tmp, 1);
	else if (f->t.y < f->t.len && f->t.m == 1)
		ft_s_x_r(f, f->t.tmp, 1);
	else if (f->t.y < f->t.len && f->t.m == 0)
		ft_s_x(f, f->t.tmp, 1);
}

int			ft_upper_s(t_pf *f, va_list pa)
{
	wchar_t *str;

	str = va_arg(pa, wchar_t *);
	return (f->t.res += ft_putwstr(str));
}

int			ft_s(t_pf *f, va_list pa)
{
	int		i;
	char	*str;

	if (f->t.l == 1)
		return (ft_upper_s(f, pa));
	str = va_arg(pa, char*);
	if (str == NULL)
	{
		f->t.res += ft_putstr("(null)");
		return (6);
	}
	f->t.len = ft_strlen(str);
	i = 0;
	if (f->t.dat == 0 && f->t.x == 0 && f->t.y == 0)
		f->t.res += ft_putstr(str);
	else if (f->t.dat == 1 && f->t.x == 0)
		ft_s_dat(f, str);
	else if (f->t.dat == 0 && f->t.x > 0 && f->t.m == 0 && f->t.y == 0)
		ft_s_x(f, str, 0);
	else if (f->t.dat == 0 && f->t.x > 0 && f->t.m == 1 && f->t.y == 0)
		ft_s_x_r(f, str, 0);
	else if (f->t.dat == 1 && f->t.x > 0 && f->t.y > 0)
		ft_s_x_dat(f, str);
	zero(f);
	return (0);
}
