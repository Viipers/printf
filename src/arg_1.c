/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:38:00 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/21 11:22:35 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_uihex(va_list ap, t_set *param)
{
	unsigned int value;

	value = va_arg(ap, unsigned int);
	ft_putuihex_count(value, param);
}

void	arg_uihexm(va_list ap, t_set *param)
{
	unsigned int value;

	value = va_arg(ap, unsigned int);
	ft_putuihexm_count(value, param);
}

void	arg_uint(va_list ap, t_set *param)
{
	unsigned int value;

	value = va_arg(ap, unsigned int);
	ft_putunbr_count(value, param);
}

void	arg_int(va_list ap, t_set *param)
{
	int value;

	value = va_arg(ap, int);
	ft_putnbr_count(value, param);
}

void	arg_void(va_list ap, t_set *param)
{
	unsigned long value;

	value = (unsigned long)va_arg(ap, void *);
	ft_putultoh_count(value, param);
}
