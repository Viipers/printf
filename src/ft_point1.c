/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:19:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/04 11:46:56 by tsannie          ###   ########.fr       */
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
		test_supzero(str, param, value);
	if (param->af_point == 0)
		test_equalszero(str, param, value);
	if (param->af_point < 0)
		test_lesszero(str, param, value, p_zero);
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
	int		neg;

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
		neg = (str[param->i] == '-') ? 1 : 0;
		(neg == 1) ? param->i++ : 0;
		while (str[param->i] >= '0' && str[param->i] <= '9')
		{
			param->af_point = param->af_point * 10 + (str[param->i] - '0');
			param->i++;
		}
		param->af_point = (neg == 1) ? -param->af_point : param->af_point;
	}
	dispatch_point(str, param, ap, starneg);
}
