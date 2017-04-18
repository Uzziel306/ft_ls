/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_i_d(t_pf *f, char *str)
{
	if (f->t.plus == 1 && str[0] != '-')
		f->t.res += ft_putchar('+');
	if (str[0] == '-')
	{
		str += 1;
		f->t.res += ft_putchar('-');
		f->t.len -= 1;
	}
	while (f->t.len < f->t.y)
	{
		f->t.res += ft_putchar('0');
		f->t.len += 1;
	}
	f->t.res += ft_putstr(str);
	return (0);
}

int			ft_i_x(t_pf *f, char *str)
{
	char c;

	c = ' ';
	if (f->t.plus == 1 && str[0] != '-' && str[0] != '-')
	{
		f->t.res += ft_putchar('+');
		f->t.len += 1;
	}
	if (f->t.z == 1)
	{
		c = '0';
		f->t.res += ft_putchar('0');
		f->t.len += 1;
	}
	while (f->t.len < f->t.x)
	{
		f->t.res += ft_putchar(c);
		f->t.len += 1;
	}
	f->t.res += ft_putstr(str);
	return (0);
}

int			ft_i_x_complex(t_pf *f, char *str)
{
	if (f->t.s == 1)
		f->t.res += ft_putchar(' ');
	if (f->t.plus == 1 && str[0] != '-')
		str = ft_strjoin("+", str);
	while (f->t.len < f->t.x)
	{
		f->t.res += ft_putchar(' ');
		f->t.len += 1;
	}
	f->t.res += ft_putstr(str);
	return (0);
}

int			ft_i_x_complex_1(t_pf *f, char *str)
{
	int		j;

	if (f->t.s == 1)
		f->t.res += ft_putchar(' ');
	if (str[0] == '-')
	{
		str += 1;
		f->t.res += ft_putchar('-');
		f->t.len -= 1;
		f->t.x -= 1;
	}
	j = f->t.y;
	if (f->t.plus == 1)
		j += 1;
	while (j < f->t.x)
	{
		f->t.res += ft_putchar(' ');
		j++;
	}
	ft_i_d(f, str);
	return (0);
}

int			ft_i_x_r(t_pf *f, char *str)
{
	if (f->t.plus == 1 && f->t.z == 0 && str[0] != '-')
	{
		str = ft_strjoin("+", str);
		f->t.len += 1;
	}
	f->t.res += ft_putstr(str);
	while (f->t.len < f->t.x)
	{
		f->t.res += ft_putchar(' ');
		f->t.len += 1;
	}
	return (0);
}
