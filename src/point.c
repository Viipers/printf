/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:19:38 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/17 17:17:15 by tsannie          ###   ########.fr       */
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
	param->zero = 1;
	if (param->af_point > 0)
	{
		if (str[param->i] == 'd' || str[param->i] == 'i')
		{
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
		}
		if (str[param->i] == 'u')
		{
			put_space(param->af_point, ft_nbcharuint((unsigned int)value), param);
			ft_putunbr_count((unsigned int)value, param);
		}
		if (str[param->i] == 'x')
		{
			put_space(param->af_point, ft_nbcharuihex((unsigned int)value), param);
			ft_putuihex_count((unsigned int)value, param);
		}
		if (str[param->i] == 'X')
		{
			put_space(param->af_point, ft_nbcharuihex((unsigned int)value), param);
			ft_putuihexm_count((unsigned int)value, param);
		}
		if (str[param->i] == 'p')
		{
			param->without_pre = 0;
			ft_putstr_count("0x", param);
			put_space(param->af_point, ft_nbcharhex((unsigned long)value), param);
			ft_putultoh_count((unsigned long)value, param);
			param->without_pre = 1;
		}
	}
	else if (param->af_point == 0)
	{
		if (str[param->i] == 'p')
		{
			if (value == NULL)
			{
				ft_putstr_count("0x", param);
			}
		}
	}
	param->zero = 0;
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
