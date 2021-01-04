/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:57:55 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/27 18:58:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_lesszero2(char *str, t_set *param, void *value, int p_zero)
{
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
			put_space(param->stock_star, ft_nbcharhex((unsigned long)value) + 2,
			param);
			ft_putultoh_count((unsigned long)value, param);
			param->without_pre = 1;
		}
	}
}

void	test_lesszero(char *str, t_set *param, void *value, int p_zero)
{
	if (str[param->i] == 'd' || str[param->i] == 'i')
	{
		if (p_zero == 0 || (int)value >= 0)
			ft_putnbr_count((int)value, param);
		else
		{
			if ((int)value == I_MIN)
				ft_putnbr_count((int)value, param);
			else
			{
				ft_putchar_count('-', param);
				put_space(param->stock_star, ft_nbcharint((int)value), param);
				ft_putnbr_count((int)value * -1, param);
			}
		}
	}
	test_lesszero2(str, param, value, p_zero);
}

void	test_equalszero(char *str, t_set *param, void *value)
{
	if (str[param->i] == 'p')
		if (value == NULL)
			ft_putstr_count("0x", param);
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

void	test_supzero2(char *str, t_set *param, void *value)
{
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

void	test_supzero(char *str, t_set *param, void *value)
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
	test_supzero2(str, param, value);
}
