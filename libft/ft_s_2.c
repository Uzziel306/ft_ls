/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_s_dat(t_pf *f, char *str)
{
	int		i;

	i = 0;
	if (f->t.y == 0)
		return (0);
	while (str[i] != '\0' && i < f->t.y)
	{
		f->t.res += ft_putchar(str[i]);
		i += 1;
	}
	return (0);
}

int			ft_s_x(t_pf *f, char *str, int flag)
{
	if (flag == 1)
		f->t.tmp[f->t.y] = '\0';
	f->t.len = ft_strlen(str);
	if (f->t.len >= f->t.x)
		f->t.res += ft_putstr(str);
	else
	{
		f->t.x -= f->t.len;
		while (f->t.i < f->t.x)
		{
			f->t.res += ft_putchar(' ');
			f->t.i += 1;
		}
		f->t.res += ft_putstr(str);
	}
	return (0);
}
