/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						u_putnbr(unsigned long long int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int							ft_u(t_pf *f, va_list pa)
{
	unsigned long long int	i;

	i = va_arg(pa, unsigned long long int);
	f->t.nb = ft_itoa_basel(i, 10);
	return (f->t.res += ft_putstr(f->t.nb));
}

int							ft_digitnuml(unsigned long long int n, int base)
{
	int						i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char						*ft_itoa_basel
	(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_digitnuml(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}

int							ft_o(t_pf *f, va_list pa)
{
	unsigned int			i;

	i = va_arg(pa, unsigned long long int);
	if (f->t.ht == 1 && i != 0)
		f->t.res += ft_putchar('0');
	f->t.nb = ft_itoa_basel(i, 8);
	return (f->t.res += ft_putstr(f->t.nb));
}
