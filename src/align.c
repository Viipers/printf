/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:45:52 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/01 19:02:13 by tsannie
          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_nextright(char *str, t_set *param, int glob, void *value)
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
	{
		param->i++;
		param->af_point = 0;
		while (str[param->i] >= '0' && str[param->i] <= '9')
		{
			param->af_point = param->af_point * 10 + (str[param->i] - '0');
			param->i++;
		}
		if (str[param->i] == 's')
		{
			if ((char *)value == NULL)
				value = "(null)";
			put_space(glob, ft_minvalue(param->af_point, (int)ft_strlen((char*) value)), param);
		}
		param->zero = 0;
		if (str[param->i] == 'd' || str[param->i] == 'i')
		{
			if (param->af_point == 0)
				put_space(glob, 0, param);
			else if ((int)value < 0)
				put_space(glob, ft_maxvalue(param->af_point + 1, ft_nbcharint((int)value)), param);
			else
				put_space(glob, ft_maxvalue(param->af_point, ft_nbcharint((int)value)), param);
		}
		if (str[param->i] == 'u' || str[param->i] == 'x' || str[param->i] == 'X')
		{
			if (param->af_point == 0)
				put_space(glob, 0, param);
			else
				put_space(glob, ft_maxvalue(param->af_point, ft_nbcharuint((int)value)), param);
		}
		if (str[param->i] == 'p')
		{
			if (param->af_point == 0)
				put_space(glob, 2, param);
			else
			{
				printf("\naf_point\t=\t%d\nvalue\t\t=\t%d\nmax_value\t=\t%d\n", param->af_point, ft_nbcharuint((unsigned long)value), ft_maxvalue(param->af_point , ft_nbcharuint((unsigned long)value)));
				put_space(glob, ft_maxvalue(param->af_point , ft_nbcharuint((unsigned long)value)), param);
			}
		}
		param->zero = 1;
		test_point(str, param, value);
	}
}

void	test_right(char *str, t_set *param, va_list ap, int glob)
{
	void *value;

	value = va_arg(ap, void*);
	if (str[param->i] == 'i' || str[param->i] == 'd')
	{
		if (param->zero == 1 && (int)value < 0)
		{
			ft_putchar_count('-', param);
			put_space(glob, ft_nbcharint((int)value), param);
			ft_putnbr_count((int)value * -1, param);
		}
		else
		{
			put_space(glob, ft_nbcharint((int)value), param);
			ft_putnbr_count((int)value, param);
		}
	}
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
	test_nextright(str, param, glob, value);
}

void	right_align(char *str, t_set *param, va_list ap)
{
	int	glob;

	glob = 0;
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
	while (str[param->i] >= '0' && str[param->i] <= '9')
	{
		glob = glob * 10 + (str[param->i] - '0');
		param->i++;
	}
	param->i--;
	trim_param(str, param, ap);
	put_space(glob, param->nbchar_output, param);
	param->nbchar_output = 0;
}

void	zero_align(char *str, t_set *param, va_list ap)
{
	if (str[param->i + 1] >= '0' && str[param->i + 1] <= '9')
	{
		param->i++;
		param->zero = 1;
		right_align(str, param, ap);
		param->zero = 0;
	}
	else
	{
		trim_param(str, param, ap);
	}
}
