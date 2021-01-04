/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:11:03 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/27 19:59:24 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	right_align(char *str, t_set *param, va_list ap)
{
	int	glob;

	glob = 0;
	if (param->first_star == 1)
		glob = param->stock_star;
	if (str[param->i] == '*')
	{
		glob = va_arg(ap, int);
		param->i++;
	}
	while (str[param->i] >= '0' && str[param->i] <= '9')
	{
		glob = glob * 10 + (str[param->i] - '0');
		param->i++;
	}
	test_right(str, param, ap, glob);
}

void	left_align(char *str, t_set *param, va_list ap)
{
	int	glob;

	param->i++;
	glob = 0;
	if (param->first_star == 1)
		glob = param->stock_star;
	if (str[param->i] == '*')
	{
		glob = va_arg(ap, int);
		if (glob < 0)
			glob = glob * -1;
		param->i++;
	}
	while (str[param->i] >= '0' && str[param->i] <= '9')
	{
		glob = glob * 10 + (str[param->i] - '0');
		param->i++;
	}
	param->i--;
	trim_param(str, param, ap);
	put_space(glob, param->nbchar_output, param);
}

void	zero_align(char *str, t_set *param, va_list ap)
{
	if ((str[param->i + 1] >= '0' && str[param->i + 1] <= '9')
	|| str[param->i + 1] == '*')
		param->zero = 1;
	trim_param(str, param, ap);
	param->zero = 0;
}
