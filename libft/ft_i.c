/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_i_x_complex_2(t_pf *f, char *str)
{
	if (f->t.s == 1)
		f->t.res += ft_putchar(' ');
	ft_i_d(f, str);
	while (f->t.y < f->t.x)
	{
		f->t.res += ft_putchar(' ');
		f->t.y += 1;
	}
	return (0);
}

int							ft_i_print(t_pf *f, char *str)
{
	if (f->t.s == 1 && str[0] != '-')
		f->t.res += ft_putchar(' ');
	if (f->t.plus == 1 && f->t.m == 0 && str[0] != '-')
		f->t.res += ft_putchar('+');
	f->t.res += ft_putstr(str);
	return (0);
}

int							ft_i_2(t_pf *f, char *str)
{
	if (f->t.z == 123454)
		f->t.res += ft_putstr("Tu mama en tangota");
	else if (f->t.dat == 1 && f->t.len >= f->t.y && f->t.x == 0)
		return (ft_i_print(f, str));
	else if (f->t.dat == 1 && (f->t.len - 1) < f->t.y && f->t.x == 0)
		return (ft_i_d(f, str));
	else if (f->t.dat == 0 && f->t.y == 0 && f->t.x > 0 && f->t.m == 0)
		return (ft_i_x(f, str));
	else if (f->t.dat == 0 && f->t.y == 0 && f->t.x > 0 && f->t.m == 1)
		return (ft_i_x_r(f, str));
	else if (f->t.x <= f->t.len && f->t.y > f->t.len)
		return (ft_i_d(f, str));
	else if (f->t.y <= f->t.len && f->t.x <= f->t.len)
		return (ft_i_print(f, str));
	else if (f->t.y < f->t.len && f->t.x >= f->t.len)
		return (ft_i_x_complex(f, str));
	else if (f->t.y >= f->t.len && f->t.x > f->t.len && f->t.m == 0)
		return (ft_i_x_complex_1(f, str));
	else if (f->t.y >= f->t.len && f->t.x > f->t.len && f->t.m == 1)
		return (ft_i_x_complex_2(f, str));
	zero(f);
	return (0);
}

int							ft_i_flags(t_pf *f, va_list pa)
{
	unsigned long long int	nb;

	if (f->t.zz == 1 || f->t.c == 'D')
	{
		nb = va_arg(pa, unsigned long long int);
		f->t.nb = ft_itoa_basel(nb, 10);
		f->t.res += ft_putstr(f->t.nb);
		return (1);
	}
	return (0);
}

int							ft_i(t_pf *f, va_list pa)
{
	char					*str;
	int						nb;

	if (ft_i_flags(f, pa))
		return (0);
	nb = va_arg(pa, int);
	str = ft_itoa(nb);
	f->t.len = ft_strlen(str);
	if (f->t.m == 0 && f->t.fnb == 0 && f->t.dat == 0 && f->t.z == 0)
		return (ft_i_print(f, str));
	else if (f->t.dat == 1 && f->t.x == 0 && f->t.y == 0)
	{
		zero(f);
		return (0);
	}
	return (ft_i_2(f, str));
}
