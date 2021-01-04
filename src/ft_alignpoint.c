/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:36:51 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/27 19:57:49 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_alignpoint3(char *str, t_set *param, int glob, void *value)
{
	if (str[param->i] == 'x' || str[param->i] == 'X')
	{
		if ((unsigned int)value == 0 && param->af_point == 0)
			put_space(glob, 0, param);
		else
			put_space(glob, ft_maxvalue(param->af_point,
			ft_nbcharuihex((unsigned int)value)), param);
	}
	if (str[param->i] == 'p')
	{
		if ((unsigned long)value == 0 && param->af_point == 0)
			put_space(glob, 2, param);
		else
		{
			if (param->zero == 0)
				put_space(glob, ft_maxvalue(param->af_point,
				ft_nbcharhex((unsigned long)value)) + 2, param);
		}
	}
	test_point(str, param, value);
}

void	test_alignpoint2(char *str, t_set *param, int glob, void *value)
{
	if (str[param->i] == 'd' || str[param->i] == 'i')
	{
		if ((int)value == 0 && param->af_point == 0)
			put_space(glob, 0, param);
		else if ((int)value < 0)
		{
			if (param->zero == 0)
				put_space(glob, ft_maxvalue(param->af_point + 1,
				ft_nbcharint((int)value)), param);
		}
		else
			put_space(glob, ft_maxvalue(param->af_point,
			ft_nbcharint((int)value)), param);
	}
	if (str[param->i] == 'u')
	{
		if ((unsigned int)value == 0 && param->af_point == 0)
			put_space(glob, 0, param);
		else
			put_space(glob, ft_maxvalue(param->af_point,
			ft_nbcharuint((unsigned int)value)), param);
	}
	test_alignpoint3(str, param, glob, value);
}

void	test_alignpoint(char *str, t_set *param, int glob, void *value)
{
	param->i++;
	if (str[param->i] == '*')
		param->i++;
	else
		param->af_point = 0;
	param->first_afpoint = 1;
	while (str[param->i] >= '0' && str[param->i] <= '9')
	{
		param->af_point = param->af_point * 10 + (str[param->i] - '0');
		param->i++;
	}
	if (str[param->i] == 's')
	{
		if ((char *)value == NULL)
			value = "(null)";
		if (param->af_point >= 0)
			put_space(glob, ft_minvalue(param->af_point,
			(int)ft_strlen((char*)value)), param);
		else
			put_space(glob, ft_maxvalue(param->af_point,
			(int)ft_strlen((char*)value)), param);
	}
	if (param->af_point >= 0)
		param->zero = 0;
	test_alignpoint2(str, param, glob, value);
}
