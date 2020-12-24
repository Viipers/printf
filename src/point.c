/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:19:38 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/24 15:15:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_point(char *str, t_set *param, void *value)
{
	int p_zero;

	if (str[param->i] == 's')
	{
		if ((char *)value == NULL)
			value = "(null)";
		if (ft_strlen((char *)value) <= (size_t)param->af_point)
			ft_putstr_count((char *)value, param);
		else
			ft_putstrn_count((char *)value, param, param->af_point);
	}
	p_zero = param->zero == 1 ? 1 : 0;
	param->zero = 1;
	if (param->af_point > 0)
	{
		//printf("\nAF POINT = %d\nVALUE = %d\nCHAR = %c\n", param->af_point, value, str[param->i]);
		if (str[param->i] == 'd' || str[param->i] == 'i')
		{
			if ((int)value >= 0)
			{
				put_space(param->af_point, ft_nbcharint((int)value), param);
				ft_putnbr_count((int)value, param);
			}
			else
			{
				if ((int)value == I_MIN)
				{
					put_space(param->af_point, 11, param);
					ft_putnbr_count((int)value * -1, param);
				}
				else
				{
					ft_putchar_count('-', param);
					put_space(param->af_point, ft_nbcharint((int)value) - 1, param);
					ft_putnbr_count((int)value * -1, param);
				}
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
	if (param->af_point < 0)
	{
		if (str[param->i] == 'd' || str[param->i] == 'i')
		{
			if (p_zero == 0 || (int)value >= 0)
			{
				ft_putnbr_count((int)value, param);
			}
			else
			{
				if ((int)value == I_MIN)
				{
					ft_putnbr_count((int)value, param);
				}
				else
				{
					ft_putchar_count('-', param);
					put_space(param->stock_star, ft_nbcharint((int)value) , param);
					ft_putnbr_count((int)value * -1, param);
				}
			}
		}
		if (str[param->i] == 'u')
			ft_putunbr_count((unsigned int)value, param);
		if (str[param->i] == 'X')
			ft_putuihexm_count((unsigned int)value, param);
		if (str[param->i] == 'x')
			ft_putuihex_count((unsigned int)value, param);
		if (str[param->i] == 'p')
		{
			if (p_zero == 0)
				ft_putultoh_count((unsigned long)value, param);
			else
			{
				param->without_pre = 0;
				ft_putstr_count("0x", param);
				put_space(param->stock_star, ft_nbcharhex((unsigned long)value) + 2, param);
				ft_putultoh_count((unsigned long)value, param);
				param->without_pre = 1;
			}
		}
	}
	if (param->af_point == 0)
	{
		if (str[param->i] == 'p')
		{
			if (value == NULL)
				ft_putstr_count("0x", param);
		}
		if ((int)value != 0)
		{
			if (str[param->i] == 'd' || str[param->i] == 'i')
				ft_putnbr_count((int)value, param);
			if (str[param->i] == 'u')
				ft_putunbr_count((unsigned int)value, param);
			if (str[param->i] == 'X')
				ft_putuihexm_count((unsigned int)value, param);
			if (str[param->i] == 'x')
				ft_putuihex_count((unsigned int)value, param);
			if (str[param->i] == 'p')
				ft_putultoh_count((unsigned long)value, param);
		}
	}
	param->zero = 0;
}

void	dispatch_point(char *str, t_set *param, va_list ap, int starneg)
{
	if (param->af_point >= 0)
		test_point(str, param, va_arg(ap, void*));
	else if (param->af_point < 0 && starneg == 0)
		left_align(str, param, ap);
	else
	{
		param->i--;
		trim_param(str, param, ap);
	}
}

void	point(char *str, t_set *param, va_list ap)
{
	void	*value;
	int		starneg;

	starneg = 0;
	param->i++;
	if (str[param->i] == '*')
	{
		param->af_point = va_arg(ap, int);
		if (param->af_point < 0)
			starneg = 1;
		param->i++;
		param->first_afpoint = 1;
	}
	if (param->first_afpoint == 0)
	{
		param->af_point = 0;
		while (str[param->i] >= '0' && str[param->i] <= '9')
		{
			param->af_point = param->af_point * 10 + (str[param->i] - '0');
			param->i++;
		}
	}
	dispatch_point(str, param, ap, starneg);
}
