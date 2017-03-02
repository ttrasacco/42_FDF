/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_s_arg_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:51:00 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/07 16:51:02 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_precision(int index, const char *str, int mod)
{
	int		i;
	int		j;
	int		n;
	char	*preci;

	n = 0;
	i = ft_to_mod_i(index, mod, str);
	while (str[i] && FLAG(str[i]))
		++i;
	while (str[i] && NUM(str[i]))
		++i;
	if (str[i] == '.')
	{
		j = i - 1;
		while (str[++j] && NUM(str[j]))
			++n;
		if (!(preci = (char *)malloc(sizeof(char) * n + 1)))
			return (0);
		n = 0;
		while (str[++i] && NUM(str[i]))
			preci[n++] = str[i];
		preci[n] = '\0';
		return (ft_atoi(preci));
	}
	return (-3);
}

int		ft_to_mod_i(int index, int mod, const char *str)
{
	int		j;
	int		i;

	i = -1;
	j = 0;
	index += mod + 1;
	while (str[++i] && j < index)
		if (str[i] == '%')
			++j;
	return (i);
}

void	ft_s_skip(t_arg *tmp, int index, const char *str, int mod)
{
	int		i;

	i = ft_to_mod_i(index, mod, str);
	tmp->s_skip = (tmp->type_conv == -1) ? 1 : 2;
	while (NUM(str[i]) || FLAG(str[i]) || str[i] == '.')
	{
		tmp->s_skip++;
		++i;
	}
	while (SCD_FLAG(str[i]))
	{
		tmp->s_skip++;
		++i;
	}
}

int		ft_scd_flag(int index, const char *str, int mod)
{
	int		i;

	i = ft_to_mod_i(index, mod, str);
	while (str[i] && FLAG(str[i]))
		++i;
	while (str[i] && NUM(str[i]))
		++i;
	if (str[i] == '.')
	{
		++i;
		while (str[i] == NUM(str[i]))
			++i;
	}
	return (ft_which_scd_flag(str, i));
}

int		ft_which_scd_flag(const char *str, int i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (0);
	else if (str[i] == 'h' && str[i + 1] != 'h')
		return (1);
	else if ((str[i] == 'l' && str[i + 1] != 'l') || str[i] == 'z')
		return (3);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (4);
	else if (str[i] == 'j')
		return (5);
	else
		return (2);
}
