/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:08:44 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/27 19:01:44 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	star(char *str, t_set *param, va_list ap)
{
	param->first_star = 1;
	param->stock_star = va_arg(ap, int);
	if (param->zero == 1 && param->stock_star < 0)
		param->zero = 0;
	if (param->stock_star > 0)
	{
		param->i++;
		right_align(str, param, ap);
	}
	if (param->stock_star < 0)
	{
		param->stock_star = param->stock_star * -1;
		left_align(str, param, ap);
	}
	if (param->stock_star == 0)
	{
		zero_align(str, param, ap);
	}
	param->first_star = 0;
}
