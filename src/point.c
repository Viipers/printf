/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:19:38 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/15 17:52:48 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_point(char *str, t_set *param, void *value)
{
	if (str[param->i] == 's')
	{
		if (ft_strlen((char *)value) <= (size_t)param->af_point)
			ft_putstr_count((char *)value, param);
		else
			ft_putstrn_count((char *)value, param, param->af_point);
	}
}

void	point(char *str, t_set *param, va_list ap)
{
	void *value;

	param->i++;
	value = va_arg(ap, void*);
	if (param->af_point == -1)
	{
		param->af_point = 0;
		while (str[param->i] >= '0' && str[param->i] <= '9')
		{
			param->af_point = param->af_point * 10 + (str[param->i] - '0');
			param->i++;
		}
	}
	test_point(str, param, value);
}
