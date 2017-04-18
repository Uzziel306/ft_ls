/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chose_format(t_pf *f, va_list pa)
{
	if (f->t.c == 's' || f->t.c == 'S')
		ft_s(f, pa);
	else if (f->t.c == 'c' || f->t.c == 'C')
		ft_c(f, va_arg(pa, int));
	else if (f->t.c == 'i' || f->t.c == 'd' || f->t.c == 'D')
		ft_i(f, pa);
	else if (f->t.c == 'u' || f->t.c == 'U')
		ft_u(f, pa);
	else if (f->t.c == 'p')
		ft_p(f, pa);
	else if (f->t.c == 'x' || f->t.c == 'X')
		ft_x(f, pa);
	else if (f->t.c == 'o' || f->t.c == 'O')
		ft_o(f, pa);
	else if (f->t.c == '%')
		f->t.res += ft_putchar('%');
	zero(f);
	return (0);
}

void	zero(t_pf *f)
{
	f->t.i = 0;
	f->t.j = 0;
	f->t.k = 0;
	f->t.len = 0;
	f->t.x = 0;
	f->t.y = 0;
	f->t.m = 0;
	f->t.dat = 0;
	f->t.dat_nb = 0;
	f->t.fnb = 0;
	f->t.c = ' ';
	f->t.decimalnumber = 0;
	f->t.quotient = 0;
	f->t.count = 0;
	f->t.temp = 0;
	f->t.nb = ft_strnew(0);
	f->t.nb2 = ft_strnew(0);
	f->t.pluss = ft_strnew(0);
}
