/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_get_format(char c)
{
	char	*format;
	int		i;

	i = 0;
	format = ft_strnew(15);
	format = "sSpdDioOuUxXcC%";
	while (format[i] != '\0')
	{
		if (format[i] == c)
			return (c);
		i++;
	}
	return (0);
}

void		ft_get_nb(t_pf *f, int flag, char **str)
{
	if (flag == 1)
	{
		f->t.nb[f->t.j] = **str;
		f->t.y = ft_atoi(f->t.nb);
		f->t.j += 1;
		f->t.fnb += 1;
	}
	else if (flag == 2)
	{
		f->t.nb2[f->t.k] = **str;
		f->t.x = ft_atoi(f->t.nb2);
		f->t.k += 1;
		f->t.fnb += 1;
	}
}

int			ft_getflags(char *flag, t_pf *f)
{
	if (flag[0] == 'h' && flag[1] && flag[1] != 'h')
		f->t.h = 1;
	else if (flag[0] == 'h' && flag[1] && flag[1] == 'h')
		f->t.hh = 1;
	else if (flag[0] == 'l' && flag[1] && flag[1] != 'l')
		f->t.l = 1;
	else if (flag[0] == 'l' && flag[1] && flag[1] == 'l')
		f->t.ll = 1;
	else if (flag[0] == 'j')
		f->t.l = 1;
	else if (flag[0] == 'z')
		f->t.zz = 1;
	return (0);
}

int			ft_getval(char **s, t_pf *f, va_list pa)
{
	while (**s)
	{
		if (**s == '.')
			f->t.dat = 1;
		else if (**s == '-')
			f->t.m = 1;
		else if (**s == '+')
			f->t.plus = 1;
		else if (**s == '#')
			f->t.ht = 1;
		else if ((**s == '0') && ((*(*s - 1)) == '%' || (*(*s - 1)) == '+'))
			f->t.z = 1;
		else if (**s == ' ' && (*(*s - 1)) == '%')
			f->t.s = 1;
		else if (ft_isdigit(**s) && f->t.dat != 0)
			ft_get_nb(f, 1, s);
		else if (ft_isdigit(**s) && f->t.dat != 1)
			ft_get_nb(f, 2, s);
		else if (ft_isalpha(**s))
			ft_getflags(*s, f);
		if ((f->t.c = ft_get_format(**s)))
			return (ft_chose_format(f, pa));
		*s += 1;
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_pf	*f;
	va_list	pa;
	char	*str;

	va_start(pa, format);
	str = ft_strdup(format);
	f = (t_pf*)malloc(sizeof(t_pf));
	zero(f);
	f->t.res = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str += 1;
			ft_getval(&str, f, pa);
		}
		else
			f->t.res += ft_putchar(*str);
		str++;
	}
	va_end(pa);
	return (f->t.res);
}
