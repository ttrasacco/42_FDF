/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:12:37 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:12:39 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*ft_fill_str(intmax_t i)
{
	char	*str;

	if (i == (LONG_MIN))
	{
		if (!(str = (char*)malloc(sizeof(char) * 20)))
			return (NULL);
		ft_strcpy(str, "9223372036854775808\0");
	}
	else
		str = (i < 0 ? ft_itoa(-(intmax_t)i) : ft_itoa((intmax_t)i));
	return (str);
}

int			ft_print_d_maj(t_arg elem, va_list *ap)
{
	intmax_t	i;
	int			r;
	int			n;
	int			j;
	char		*str;

	i = (intmax_t)va_arg(*ap, long long int);
	r = 0;
	str = ft_fill_str(i);
	j = (PRECI > ft_strlen(str) ? PRECI - ft_strlen(str) : 0);
	n = SMIN - ft_strlen(str) - j;
	n += (SPACE || PLUS || i < 0 ? 0 : 1);
	while (!elem.minus && (PRECI != -3 || !ZERO) && --n > 0 && ++r)
		ft_putchar(PRECI == -3 && ZERO ? '0' : ' ');
	r += (i < 0 ? ft_putchar('-') : 0);
	r += (i >= 0 && PLUS ? ft_putchar('+') : 0);
	r += (i >= 0 && !PLUS && SPACE ? ft_putchar(' ') : 0);
	while (!elem.minus && PRECI == -3 && ZERO && --n > 0 && ++r)
		ft_putchar(PRECI == -3 && ZERO ? '0' : ' ');
	while (j-- > 0 && ++r)
		ft_putchar('0');
	r += ft_putstr(str);
	while (--n > 0 && ++r)
		ft_putchar(' ');
	return (r);
}
