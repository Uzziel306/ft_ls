/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					resul_hex(t_pf *f)
{
	int				a;

	a = 55;
	if (f->t.c == 'x')
		a = 87;
	f->t.count = 0;
	if (f->t.decimalnumber == 0)
	{
		write(1, "0", 1);
		f->t.count += 1;
	}
	f->t.i = 0;
	f->t.quotient = f->t.decimalnumber;
	while (f->t.quotient != 0)
	{
		f->t.temp = f->t.quotient % 16;
		if (f->t.temp < 10)
			f->t.temp = f->t.temp + 48;
		else
			f->t.temp = f->t.temp + a;
		f->t.hexadecimalnumber[f->t.i++] = f->t.temp;
		f->t.quotient = f->t.quotient / 16;
		f->t.count++;
	}
	return (f->t.count);
}

char				*reverse_array(char *s)
{
	int				i;
	int				j;
	char			*x;

	j = 0;
	i = ft_strlen(s);
	x = (char*)malloc(i);
	i -= 1;
	while (i != -1)
	{
		x[j] = s[i];
		i--;
		j++;
	}
	ft_strcpy(s, x);
	return (s);
}

char				*ft_strlowcase(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}

int					p_solver(t_pf *f, long i)
{
	f->t.decimalnumber = i;
	if (f->t.decimalnumber >= 0)
		resul_hex(f);
	else
	{
		f->t.decimalnumber = f->t.decimalnumber + 4294967296;
		resul_hex(f);
	}
	reverse_array(f->t.hexadecimalnumber);
	ft_strlowcase(f->t.hexadecimalnumber);
	f->t.res += ft_putstr(f->t.hexadecimalnumber);
	return (f->t.count);
}

int					ft_p(t_pf *f, va_list ap)
{
	long			i;

	f->t.res += ft_putstr("0x");
	i = (long)va_arg(ap, void*);
	i = p_solver(f, i);
	return (i);
}
