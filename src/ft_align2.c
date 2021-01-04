/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:10:33 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/27 19:58:50 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_right3(char *str, t_set *param, int glob, void *value)
{
	if (str[param->i] == 'u')
	{
		put_space(glob, ft_nbcharuint((unsigned int)value), param);
		ft_putunbr_count((unsigned int)value, param);
	}
	if (str[param->i] == 'x')
	{
		put_space(glob, ft_nbcharuihex((unsigned int)value), param);
		ft_putuihex_count((unsigned int)value, param);
	}
	if (str[param->i] == 'X')
	{
		put_space(glob, ft_nbcharuihex((unsigned int)value), param);
		ft_putuihexm_count((unsigned int)value, param);
	}
	if (str[param->i] == '.')
		test_alignpoint(str, param, glob, value);
}

void	test_right2(char *str, t_set *param, int glob, void *value)
{
	if (str[param->i] == 'i' || str[param->i] == 'd')
	{
		if (param->zero == 1 && (int)value < 0)
		{
			if ((int)value == I_MIN)
			{
				put_space(param->af_point, 11, param);
				ft_putnbr_count((int)value * -1, param);
			}
			else
			{
				ft_putchar_count('-', param);
				put_space(glob, ft_nbcharint((int)value), param);
				ft_putnbr_count((int)value * -1, param);
			}
		}
		else
		{
			put_space(glob, ft_nbcharint((int)value), param);
			ft_putnbr_count((int)value, param);
		}
	}
	test_right3(str, param, glob, value);
}

void	test_right(char *str, t_set *param, va_list ap, int glob)
{
	void *value;

	if (str[param->i] == '.' && str[param->i + 1] == '*')
		param->af_point = va_arg(ap, int);
	value = va_arg(ap, void*);
	if (str[param->i] == 's')
	{
		if ((char *)value == NULL)
			value = "(null)";
		put_space(glob, ft_strlen((char *)value), param);
		ft_putstr_count((char *)value, param);
	}
	if (str[param->i] == '%' || str[param->i] == 'c')
	{
		put_space(glob, 1, param);
		str[param->i] == '%' ? ft_putchar_count('%', param)
							: ft_putchar_count((char)value, param);
	}
	if (str[param->i] == 'p')
	{
		put_space(glob, ft_nbcharhex((unsigned long)value) + 2, param);
		ft_putultoh_count((unsigned long)value, param);
	}
	test_right2(str, param, glob, value);
}
