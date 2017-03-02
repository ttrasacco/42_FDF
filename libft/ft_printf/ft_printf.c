/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:02:17 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/06 18:02:19 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_count_arg(const char *format)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (format[++i])
		if (format[i] == '%')
			++j;
	return (j);
}

int		ft_putstr_to(const char *format, int *i, char c)
{
	int		j;

	j = *i;
	while (format[*i] && format[*i] != c)
	{
		ft_putchar(format[*i]);
		++*i;
	}
	return (*i - j);
}

int		ft_use_arg(t_arg *elem, int *n)
{
	int		i;

	i = 0;
	if (elem->type_conv == 14)
		i = MOD;
	if (elem->type_conv > 14)
		i = ft_print_bad_arg(*elem);
	if (elem->type_conv == -1)
		--*n;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	*elem;
	int		i;
	int		n;
	int		r;

	if (format == NULL)
		return (0);
	n = ft_count_arg(format);
	ft_fill_s_arg(&elem, n, format);
	va_start(ap, format);
	i = 0;
	r = 0;
	while (n > 0)
	{
		r += ft_putstr_to(format, &i, '%');
		r += (elem->type_conv > 13 || elem->type_conv < 0) ?\
		ft_use_arg(elem, &n) : ft_tab_functions(elem, &ap);
		i += elem->s_skip;
		ft_elem_next(elem, &n);
	}
	va_end(ap);
	r += ft_putstr_to(format, &i, '\0');
	return (r);
}
