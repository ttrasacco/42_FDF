/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_s_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:08:31 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/06 18:08:33 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

char	*ft_str_flags(int index, const char *str, int mod)
{
	int		i;
	int		j;
	int		n;
	char	*str_flag;

	i = 0;
	j = 0;
	n = 0;
	index += mod + 1;
	while (str[i] && j < index)
	{
		if (str[i] == '%')
			++j;
		++i;
	}
	j = i;
	while (FLAG(str[++i]))
		++n;
	if (!(str_flag = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	n = 0;
	while (FLAG(str[j]))
		str_flag[n++] = str[j++];
	str_flag[n] = '\0';
	return (str_flag);
}

int		ft_which_conv(int index, const char *str, int *mod)
{
	int		i;
	int		j;
	int		n;

	j = 0;
	n = -1;
	i = ft_to_mod_i(index, *mod, str);
	while (str[i] && FLAG(str[i]))
		++i;
	while (str[i] && NUM(str[i]))
		++i;
	if (str[i] == '.')
		++i;
	while (str[i] && NUM(str[i]))
		++i;
	while (SCD_FLAG(str[i]))
		++i;
	while (CONV[++n])
		if (str[i] == CONV[n])
			return (n);
	return (ft_isprint(str[i]) ? str[i] : -1);
}

int		ft_size_min(int index, const char *str, int mod)
{
	int		i;
	int		j;
	int		n;
	char	*s_min;

	j = 0;
	i = -1;
	n = 0;
	index += mod + 1;
	while (str[++i] && j < index)
		if (str[i] == '%')
			++j;
	while (FLAG(str[i]))
		++i;
	j = i - 1;
	while (NUM(str[++j]))
		++n;
	s_min = ft_strnew(n);
	n = 0;
	while (NUM(str[i]))
		s_min[n++] = str[i++];
	return (ft_atoi(s_min));
}

void	ft_which_flags(t_arg *tmp)
{
	int		i;

	i = -1;
	tmp->sharp = 0;
	tmp->space = 0;
	tmp->minus = 0;
	tmp->plus = 0;
	tmp->zero = 0;
	while (tmp->flags[++i])
	{
		if (tmp->flags[i] == '#')
			tmp->sharp = 1;
		if (tmp->flags[i] == '-')
			tmp->minus = 1;
		if (tmp->flags[i] == '+')
			tmp->plus = 1;
		if (tmp->flags[i] == '0')
			tmp->zero = 1;
		if (tmp->flags[i] == ' ')
			tmp->space = 1;
	}
}

void	ft_fill_s_arg(t_arg **first, int n, const char *str)
{
	int		i;
	int		mod;
	t_arg	*tmp;

	mod = 0;
	if (!(tmp = (t_arg *)malloc(sizeof(t_arg))))
		exit(1);
	*first = tmp;
	i = -1;
	while (++i < n)
	{
		tmp->flags = ft_str_flags(i, str, mod);
		tmp->s_min = ft_size_min(i, str, mod);
		tmp->preci = ft_precision(i, str, mod);
		tmp->scd_flag = ft_scd_flag(i, str, mod);
		ft_which_flags(tmp);
		tmp->type_conv = ft_which_conv(i, str, &mod);
		ft_s_skip(tmp, i, str, mod);
		if (!(tmp->next = (t_arg *)malloc(sizeof(t_arg))))
			exit(1);
		tmp = tmp->next;
	}
	tmp->next = NULL;
}
