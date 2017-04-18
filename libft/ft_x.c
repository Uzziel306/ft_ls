/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_x(t_pf *f, va_list pa)
{
	f->t.decimalnumber = va_arg(pa, long);
	if (f->t.ht == 1 && f->t.decimalnumber != 0 && f->t.c == 'X')
		f->t.res += ft_putstr("0X");
	else if (f->t.ht == 1 && f->t.decimalnumber != 0 && f->t.c == 'x')
		f->t.res += ft_putstr("0x");
	if (f->t.decimalnumber >= 0)
		resul_hex(f);
	else
	{
		f->t.decimalnumber = f->t.decimalnumber + 4294967296;
		resul_hex(f);
	}
	reverse_array(f->t.hexadecimalnumber);
	f->t.res += ft_putstr(f->t.hexadecimalnumber);
	return (f->t.count);
}
