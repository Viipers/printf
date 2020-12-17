/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:19:38 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/17 10:51:25 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_point(char *str, t_set *param, void *value)
{
	if (str[param->i] == 's')
	{
		if ((char *)value == NULL)
			value = "(null)";
		if (ft_strlen((char *)value) <= (size_t)param->af_point)
			ft_putstr_count((char *)value, param);
		else
			ft_putstrn_count((char *)value, param, param->af_point);
	}
	if (str[param->i] == 'd' || str[param->i] == 'i')
	{
		if (param->af_point > 0)
		{
			param->zero = 1;
			if ((int)value >= 0)
			{
				put_space(param->af_point, ft_nbcharint((int)value), param);
				ft_putnbr_count((int)value, param);
			}
			else
			{
				ft_putchar_count('-', param);
				put_space(param->af_point, ft_nbcharint((int)value) - 1, param);
				ft_putnbr_count((int)value * -1, param);
			}
			param->zero = 0;
		}
	}
	if (str[param->i] == 'u')
	{
		param->zero = 1;
		if (param->af_point != 0)
		{
			put_space(param->af_point, ft_nbcharuint((unsigned int)value), param);
			ft_putunbr_count((unsigned int)value, param);
		}
		param->zero = 0;
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
